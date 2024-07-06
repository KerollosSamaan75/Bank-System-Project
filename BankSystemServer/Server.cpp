#include "Server.h"

Server::Server(QObject *parent)
    : QTcpServer{parent},qin{stdin},qout{stdout}
{}

void Server::StartServer()
{
    Port = 1234;
    this->listen(QHostAddress::Any,Port);
    if(isListening())
    {
        qout<<"Server is up and listening to port =>"<<Port<<Qt::endl;
    }
    else
    {
        qout<<"Server can't listen to port =>"<<Port<<Qt::endl;
    }
}

void Server::incomingConnection(qintptr handle)
{
    qDebug()<<"User =>"<<handle<<" Connecting.."<<Qt::endl;
    ServerHandler* serverhandler =new ServerHandler(handle);
    connect(serverhandler,&QThread::finished,serverhandler,&QThread::deleteLater);
    serverhandler->start();
}
