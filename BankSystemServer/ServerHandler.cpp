#include "ServerHandler.h"

ServerHandler::ServerHandler(qint32 ID, QObject *parent)
    : QThread(parent), ID(ID)
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
    statusMessage = "User with ID: "+QString::number(ID)+" is running on thread";
    Logger::instance().logMessage(statusMessage);
    Socket = new QTcpSocket();
    Socket->setSocketDescriptor(ID);
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
    statusMessage = QString("My Server Received Data From User: %1 Data => %2").arg(ID).arg(QString(ByteArr));
    Logger::instance().logMessage(statusMessage);
    Operation(QString(ByteArr));
}

void ServerHandler::onDisconnected()
{
    if(Socket->isOpen())
    {
        Socket->close();
        statusMessage = "User with ID: "+QString::number(ID)+" has disconnected";
        Logger::instance().logMessage(statusMessage);
    }
}

void ServerHandler::Operation(QString Request)
{
    QStringList List = Request.split(":");
    if (List.isEmpty())
    {
        sendMessage("Invalid request.");
        return;
    }

    QString commandKey = List[0];
    if (commandMap.contains(commandKey))
    {
        commandMap[commandKey]->execute(List, statusMessage);
        sendMessage(statusMessage);
    }
    else
    {
        sendMessage("Unknown command.");
    }
}

void ServerHandler::sendMessage(const QString &Message)
{
    if (Socket->isOpen())
    {
        Socket->write(Message.toUtf8());
        QString logMessage = QString("My server Send Data to User: %1 Data => %2").arg(ID).arg(Message);
        Logger::instance().logMessage(logMessage);
    }
    else
    {
        QString logMessage = QString("My server Can't Send Data to User: %1 Because The Socket is Closed").arg(ID);
        Logger::instance().logMessage(logMessage);
    }
}
