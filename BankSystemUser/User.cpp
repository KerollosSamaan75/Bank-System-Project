#include "User.h"

User::User(QObject *parent)
    : QObject{parent}
{
    connect(&Socket,&QTcpSocket::connected,this,&User::onConnected);
    connect(&Socket,&QTcpSocket::disconnected,this,&User::onDisconnected);
    connect(&Socket,&QTcpSocket::errorOccurred,this,&User::onErrorOccurred);
    connect(&Socket,&QTcpSocket::stateChanged,this,&User::onStateChanged);
    connect(&Socket,&QTcpSocket::readyRead,this,&User::onReadyRead);
}

void User::ConnectToDevice(QString Ip, qint32 Port)
{
    if(Socket.isOpen())
    {
        if(this->Ip == Ip && this->Port)
        {
            return;
        }
        else
        {
            Socket.close();
            this->Port = Port;
            this->Ip = Ip;
            Socket.connectToHost(this->Ip,this->Port);
        }
    }
    else
    {
        this->Port = Port;
        this->Ip = Ip;
        Socket.connectToHost(this->Ip,this->Port);
    }
}

void User::DisconnectFromDevice()
{
    if(Socket.isOpen())
    {
        Socket.close();
    }
}

void User::WriteData(QString Data)
{
    if(Socket.isOpen())
    {
        Socket.write(Data.toUtf8());
        emit UserWriteData(Data);
    }
}

void User::onConnected()
{
    emit Connected();
}

void User::onDisconnected()
{
    emit Disconnected();
}

void User::onErrorOccurred(QAbstractSocket::SocketError socketError)
{
    emit ErrorOccurred(socketError);
}

void User::onStateChanged(QAbstractSocket::SocketState socketState)
{
    if(socketState == QAbstractSocket::UnconnectedState)
    {
        Socket.close();
    }
    emit StateChanged(socketState);
}

void User::onReadyRead()
{
    QByteArray ByteArr = Socket.readAll();
    QString Data = QString(ByteArr);
    emit ReadyRead(Data);
}


