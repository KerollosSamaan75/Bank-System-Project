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

void User::ConnectToServer(QString Ip, qint32 Port)
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

void User::DisconnectFromServer()
{
    if(Socket.isOpen())
    {
        Socket.close();
    }
}

void User::SendRequest(QString Data)
{
    if (Socket.isOpen())
    {
        QByteArray rawData = Data.toUtf8();
        qDebug() << "User request:" << rawData;

        // Encrypt the data
        QByteArray encryptedData = encryptRequest(rawData);
        // Send the encrypted data
        Socket.write(encryptedData);
        // Emit the signal with the encrypted data for consistency
        emit UserSendRequest(encryptedData);
    }
}


QByteArray User::encryptRequest(const QByteArray &request)
{
    QByteArray key = "1234567890123456"; // 128-bit key (16 bytes)
    QByteArray iv = "1234567890123456";  // 128-bit IV (16 bytes)
    // Encrypt the request
    QByteArray encryptedRequest = QAESEncryption::Crypt(QAESEncryption::AES_128, QAESEncryption::CBC, request, key, iv, QAESEncryption::PKCS7);
    return encryptedRequest;
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


