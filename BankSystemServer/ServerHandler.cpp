#include "ServerHandler.h"

ServerHandler::ServerHandler(qint32 ID, QObject *parent)
    : QThread(parent), userID(ID)
{
    setupRequestHandles();
}

void ServerHandler::setupRequestHandles()
{
    requestHandlerMap["Login"] = new LoginHandler(dataBase);
    requestHandlerMap["AddAccount"] = new AddClientHandler(dataBase);
    requestHandlerMap["DeleteAccount"] = new DeleteAccountHandler(dataBase);
    requestHandlerMap["GetAccountBalance"] = new GetAccountBalanceHandler(dataBase);
    requestHandlerMap["GetAccountNumber"] = new GetAccountNumberHandler(dataBase);
    requestHandlerMap["GetTransactionHistory"] = new GetTransactionHistoryHandler(dataBase);
    requestHandlerMap["MakeTransaction"] = new MakeTransactionHandler(dataBase);
    requestHandlerMap["MakeTransfer"] = new MakeTransferHandler(dataBase);
    requestHandlerMap["UpdateAccount"] = new UpdateAccountHandler(dataBase);
    requestHandlerMap["GetBankDataBase"] = new GetBankDataBaseHandler(dataBase);
}

void ServerHandler::run()
{
    statusMessage = "User:"+QString::number(userID)+" is running on thread";
    logger.logMessage(statusMessage);
    Socket = new QTcpSocket();
    Socket->setSocketDescriptor(userID);
    connect(Socket, &QTcpSocket::readyRead, this, &ServerHandler::onReadyRead, Qt::DirectConnection);
    connect(Socket, &QTcpSocket::disconnected, this, &ServerHandler::onDisconnected, Qt::DirectConnection);
    dataBase.initializeMainDatabase();
    dataBase.initializeTransactionDatabase();
    exec();
}

void ServerHandler::onReadyRead()
{
    QByteArray ByteArr = Socket->readAll();
    logger.logMessage(QString("Server Received encrypted request From User:%1 Request => %2").arg(userID).arg(ByteArr.toHex()));

    // Decrypt the received data
    QByteArray decryptedData = decryptRequest(ByteArr);
    int padLength = decryptedData.at(decryptedData.length() - 1);
    decryptedData = decryptedData.left(decryptedData.length() - padLength);

    statusMessage = QString("Server Received request From User:%1 Request => %2").arg(userID).arg(QString(decryptedData));
    logger.logMessage(statusMessage);

    // Extract the frame size and validate it
    int colonIndex = decryptedData.indexOf(':');
    if (colonIndex == -1)
    {
        logger.logMessage("Invalid frame: No colon found.");
        return;
    }

    bool ok;
    int frameSize = QString(decryptedData.left(colonIndex)).toInt(&ok);
    if (!ok || frameSize <= 0)
    {
        logger.logMessage("Invalid frame: Invalid frame size.");
        return;
    }

    // Extract the JSON part of the frame and validate its size
    QByteArray jsonData = decryptedData.mid(colonIndex + 1);
    if (jsonData.size() != frameSize)
    {
        logger.logMessage("Invalid frame: Frame size does not match JSON data size.");
        return;
    }

    // Parse the JSON data
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
    if (jsonDoc.isNull() || !jsonDoc.isObject())
    {
        logger.logMessage("Invalid frame: Failed to parse JSON.");
        return;
    }

    QJsonObject jsonObj = jsonDoc.object();
    QString requestsizeStr = jsonObj["RequestSize"].toString();
    int requestSize =requestsizeStr.toInt(&ok);

    if (!ok || requestSize <= 0)
    {
        logger.logMessage(QString::number(requestSize));
        logger.logMessage("Invalid frame: Invalid request size.");
        return;
    }

    QString requestData = jsonObj["RequestData"].toString();
    if (requestData.size() != requestSize)
    {
        logger.logMessage("Invalid frame: Request size does not match actual data size.");
        return;
    }

    // Log the valid request
    statusMessage = QString("Server processing request from User:%1 Request => %2").arg(userID).arg(requestData);
    logger.logMessage(statusMessage);

    // Process the operation with the valid request data
    Operation(requestData);
}


QByteArray ServerHandler::decryptRequest(const QByteArray &encryptedData)
{
    QByteArray key = "1234567890123456"; // 128-bit key (16 bytes)
    QByteArray iv = "1234567890123456";  // 128-bit IV (16 bytes)
    // Decrypt the data
    QByteArray decryptedData = QAESEncryption::Decrypt(QAESEncryption::AES_128, QAESEncryption::CBC, encryptedData, key, iv, QAESEncryption::PKCS7);
    return decryptedData;
}


void ServerHandler::onDisconnected()
{
    if(Socket->isOpen())
    {
        Socket->close();
        statusMessage = "User:"+QString::number(userID)+" has disconnected";
        logger.logMessage(statusMessage);
    }
}

void ServerHandler::Operation(QString Request)
{
    QStringList List = Request.split(":");
    if (List.isEmpty())
    {
        sendResponse("Invalid request.");
        return;
    }

    QString HandlerKey = List[0];
    if (requestHandlerMap.contains(HandlerKey))
    {
        requestHandlerMap[HandlerKey]->execute(List, statusMessage);
        sendResponse(statusMessage);
    }
    else
    {
        sendResponse("Unknown request.");
    }
}

void ServerHandler::sendResponse(const QString &Message)
{
    if (Socket->isOpen())
    {
        // Create a QJsonObject with the request size and data
        QJsonObject requestObj;
        requestObj["ResponseSize"] =QString::number(Message.size());
        requestObj["ResponseData"] = Message;

        // Convert the QJsonObject to a QByteArray
        QJsonDocument doc(requestObj);
        QByteArray jsonData = doc.toJson(QJsonDocument::Compact);

        // Get the size of the jsonData
        qint32 jsonSize = jsonData.size();

        // Convert jsonSize to a string and append a colon
        QByteArray header = QByteArray::number(jsonSize) + ":";

        // Construct the frame by concatenating header and jsonData
        QByteArray frame = header + jsonData;
        Socket->write(frame);
        QString logMessage = QString("My server Send Response to User: %1 Response => %2").arg(userID).arg(frame);
        logger.logMessage(logMessage);

    }
    else
    {
        QString logMessage = QString("My server Can't Send Response to User: %1 Because The Socket is Closed").arg(userID);
        logger.logMessage(logMessage);
        qDebug()<<logMessage;
    }
}
