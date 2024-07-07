#include "Server.h"

Server::Server(QObject *parent)
    : QTcpServer{parent}, qin{stdin}, qout{stdout}
{}

void Server::StartServer()
{
    Port = 1234;
    this->listen(QHostAddress::Any, Port);
    if (isListening())
    {
        QString logMessage = QString("Server is up and listening to port => %1").arg(Port);
        Logger::instance().logMessage(logMessage);
    }
    else
    {
        QString logMessage = QString("Server can't listen to port => %1").arg(Port);
        Logger::instance().logMessage(logMessage);
    }
}

void Server::incomingConnection(qintptr handle)
{
    QString logMessage = QString("User connected with handle: %1").arg(handle);
    Logger::instance().logMessage(logMessage);

    ServerHandler* serverhandler = new ServerHandler(handle);
    connect(serverhandler, &QThread::finished, serverhandler, &QThread::deleteLater);
    serverhandler->start();
}
