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
        // Create a QJsonObject with the request size and data
        QJsonObject requestObj;
        requestObj["RequestSize"] =QString::number(Data.size());
        requestObj["RequestData"] = Data;

        // Convert the QJsonObject to a QByteArray
        QJsonDocument doc(requestObj);
        QByteArray jsonData = doc.toJson(QJsonDocument::Compact);

        // Get the size of the jsonData
        qint32 jsonSize = jsonData.size();

        // Convert jsonSize to a string and append a colon
        QByteArray header = QByteArray::number(jsonSize) + ":";

        // Construct the frame by concatenating header and jsonData
        QByteArray frame = header + jsonData;

        qDebug() << "User request frame:" << frame;

        // Encrypt the frame
        QByteArray encryptedData = encryptRequest(frame);

        // Send the encrypted data
        Socket.write(encryptedData);

        // Emit the signal with the encrypted data for consistency
        emit UserSendRequest(encryptedData.toHex());
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
    // Extract the frame size and validate it
    int colonIndex = ByteArr.indexOf(':');
    if (colonIndex == -1)
    {
        qDebug() << "Invalid frame: no header separator found.";
        return;
    }

    bool ok;
    int frameSize = QString(ByteArr.left(colonIndex)).toInt(&ok);
    if (!ok || frameSize <= 0)
    {
        qDebug()<<"Invalid frame: Invalid frame size.";
        return;
    }

    // Extract the JSON part of the frame and validate its size
    QByteArray jsonData = ByteArr.mid(colonIndex + 1);
    if (jsonData.size() != frameSize)
    {
        qDebug()<<"Invalid frame: Frame size does not match JSON data size.";
        return;
    }

    // Parse the JSON data
    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData);
    if (jsonDoc.isNull() || !jsonDoc.isObject())
    {
        qDebug()<<"Invalid frame: Failed to parse JSON.";
        return;
    }

    QJsonObject jsonObj = jsonDoc.object();
    QString responsesizeStr = jsonObj["ResponseSize"].toString();
    int responseSize =responsesizeStr.toInt(&ok);

    if (!ok || responseSize <= 0)
    {
        qDebug()<<(QString::number(responseSize));
        qDebug()<<"Invalid frame: Invalid response size.";
        return;
    }

    QString responseData = jsonObj["ResponseData"].toString();
    if (responseData.size() != responseSize)
    {
       qDebug()<<"Invalid frame: Response size does not match actual data size.";
        return;
    }
    emit ReadyRead(responseData);
}


