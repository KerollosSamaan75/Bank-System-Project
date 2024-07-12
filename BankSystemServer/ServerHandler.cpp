#include "ServerHandler.h"

ServerHandler::ServerHandler(qint32 ID, QObject *parent)
    : QThread(parent), userID(ID)
{
    setupRequests();
}

void ServerHandler::setupRequests()
{
    requestMap["Login"] = new LoginHandler(dataBase);
    requestMap["AddAccount"] = new AddClientHandler(dataBase);
    requestMap["DeleteAccount"] = new DeleteAccountHandler(dataBase);
    requestMap["GetAccountBalance"] = new GetAccountBalanceHandler(dataBase);
    requestMap["GetAccountNumber"] = new GetAccountNumberHandler(dataBase);
    requestMap["GetTransactionHistory"] = new GetTransactionHistoryHandler(dataBase);
    requestMap["MakeTransaction"] = new MakeTransactionHandler(dataBase);
    requestMap["MakeTransfer"] = new MakeTransferHandler(dataBase);
    requestMap["UpdateAccount"] = new UpdateAccountHandler(dataBase);
    requestMap["GetBankDataBase"] = new GetBankDataBaseHandler(dataBase);
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
    logger.logMessage("Server received encrypted request:" + ByteArr.toHex());
    // Decrypt the received data
    QByteArray decryptedData = decryptRequest(ByteArr);
    int padLength = decryptedData.at(decryptedData.length() - 1);
    decryptedData = decryptedData.left(decryptedData.length() - padLength);

    statusMessage = QString("Server Received Data From User:%1 Data => %2").arg(userID).arg(QString(decryptedData));
    logger.logMessage(statusMessage);
    qDebug()<<statusMessage;
    // Process the operation with the decrypted data
    Operation(QString(decryptedData));
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
    if (requestMap.contains(HandlerKey))
    {
        requestMap[HandlerKey]->execute(List, statusMessage);
        sendResponse(statusMessage);
    }
    else
    {
        sendResponse("Unknown Handler.");
    }
}

void ServerHandler::sendResponse(const QString &Message)
{
    if (Socket->isOpen())
    {
        Socket->write(Message.toUtf8());
        QString logMessage = QString("My server Send Data to User: %1 Data => %2").arg(userID).arg(Message);
        logger.logMessage(logMessage);
        qDebug()<<logMessage;
    }
    else
    {
        QString logMessage = QString("My server Can't Send Data to User: %1 Because The Socket is Closed").arg(userID);
        logger.logMessage(logMessage);
        qDebug()<<logMessage;
    }
}
