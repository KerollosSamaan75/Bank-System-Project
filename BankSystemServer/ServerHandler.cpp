#include "ServerHandler.h"

ServerHandler::ServerHandler(qint32 ID, QObject *parent)
    : QThread(parent), userID(ID)
{
    setupCommands();
}

void ServerHandler::setupCommands()
{
    commandMap["Login"] = new LoginCommand(dataBase);
    commandMap["AddAccount"] = new AddClientCommand(dataBase);
    commandMap["DeleteAccount"] = new DeleteAccountCommand(dataBase);
    commandMap["GetAccountBalance"] = new GetAccountBalanceCommand(dataBase);
    commandMap["GetAccountNumber"] = new GetAccountNumberCommand(dataBase);
    commandMap["GetTransactionHistory"] = new GetTransactionHistoryCommand(dataBase);
    commandMap["MakeTransaction"] = new MakeTransactionCommand(dataBase);
    commandMap["MakeTransfer"] = new MakeTransferCommand(dataBase);
    commandMap["UpdateAccount"] = new UpdateAccountCommand(dataBase);
    commandMap["GetBankDataBase"] = new GetBankDataBaseCommand(dataBase);
}

void ServerHandler::run()
{
    statusMessage = "User:"+QString::number(userID)+" is running on thread";
    Logger::instance().logMessage(statusMessage);
    Socket = new QTcpSocket();
    Socket->setSocketDescriptor(userID);
    connect(Socket, &QTcpSocket::readyRead, this, &ServerHandler::onReadyRead, Qt::DirectConnection);
    connect(Socket, &QTcpSocket::disconnected, this, &ServerHandler::onDisconnected, Qt::DirectConnection);

    dataBase.initializeMainDatabase(statusMessage);
    Logger::instance().logMessage(statusMessage);

    dataBase.initializeTransactionDatabase(statusMessage);
    Logger::instance().logMessage(statusMessage);
    exec();
}

void ServerHandler::onReadyRead()
{
    QByteArray ByteArr = Socket->readAll();
    Logger::instance().logMessage("Server received encrypted request:" + ByteArr.toHex());
    // Decrypt the received data
    QByteArray decryptedData = decryptRequest(ByteArr);
    int padLength = decryptedData.at(decryptedData.length() - 1);
    decryptedData = decryptedData.left(decryptedData.length() - padLength);

    statusMessage = QString("Server Received Data From User:%1 Data => %2").arg(userID).arg(QString(decryptedData));
    Logger::instance().logMessage(statusMessage);
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
        Logger::instance().logMessage(statusMessage);
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

    QString commandKey = List[0];
    if (commandMap.contains(commandKey))
    {
        commandMap[commandKey]->execute(List, statusMessage);
        sendResponse(statusMessage);
    }
    else
    {
        sendResponse("Unknown command.");
    }
}

void ServerHandler::sendResponse(const QString &Message)
{
    if (Socket->isOpen())
    {
        Socket->write(Message.toUtf8());
        QString logMessage = QString("My server Send Data to User: %1 Data => %2").arg(userID).arg(Message);
        Logger::instance().logMessage(logMessage);
        qDebug()<<logMessage;
    }
    else
    {
        QString logMessage = QString("My server Can't Send Data to User: %1 Because The Socket is Closed").arg(userID);
        Logger::instance().logMessage(logMessage);
        qDebug()<<logMessage;
    }
}
