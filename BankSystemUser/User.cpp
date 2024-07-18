#include "User.h"

User::User(QObject *parent)
    : QObject{parent}
{
    connect(&Socket, &QTcpSocket::connected, this, &User::onConnected); // Connect the connected signal to the onConnected slot
    connect(&Socket, &QTcpSocket::disconnected, this, &User::onDisconnected); // Connect the disconnected signal to the onDisconnected slot
    connect(&Socket, &QTcpSocket::errorOccurred, this, &User::onErrorOccurred); // Connect the errorOccurred signal to the onErrorOccurred slot
    connect(&Socket, &QTcpSocket::stateChanged, this, &User::onStateChanged); // Connect the stateChanged signal to the onStateChanged slot
    connect(&Socket, &QTcpSocket::readyRead, this, &User::onReadyRead); // Connect the readyRead signal to the onReadyRead slot
}

void User::ConnectToServer(QString Ip, qint32 Port)
{
    if (Socket.isOpen()) // Check if the socket is already open
    {
        if (this->Ip == Ip && this->Port) // Check if the IP and port are the same
        {
            return; // If same, do nothing
        }
        else
        {
            Socket.close(); // Close the socket
            this->Port = Port; // Set the new port
            this->Ip = Ip; // Set the new IP
            Socket.connectToHost(this->Ip, this->Port); // Connect to the new host
        }
    }
    else
    {
        this->Port = Port; // Set the port
        this->Ip = Ip; // Set the IP
        Socket.connectToHost(this->Ip, this->Port); // Connect to the host
    }
}

void User::DisconnectFromServer()
{
    if (Socket.isOpen()) // Check if the socket is open
    {
        Socket.close(); // Close the socket
    }
}

QString User::generateSignature(const QString& message, const QString& secretKey)
{
    QByteArray data = message.toUtf8() + secretKey.toUtf8(); // Combine message and secret key
    QByteArray hash = QCryptographicHash::hash(data, QCryptographicHash::Sha256); // Generate SHA-256 hash
    return QString(hash.toHex()); // Return the hash as a hex string
}

void User::SendRequest(QString Data)
{
    if (Socket.isOpen()) // Check if the socket is open
    {
        QProcessEnvironment env = QProcessEnvironment::systemEnvironment(); // Get system environment variables
        QString secretKey = env.value("SECRET_KEY"); // Retrieve the secret key
        qDebug() << "secretKey= " << secretKey; // Debug output for the secret key

        if (secretKey.isEmpty()) // Check if the secret key is empty
        {
            qWarning() << "Secret key is not set in the environment variables."; // Warning if secret key is not set
            return; // Exit the function
        }

        QString signature = generateSignature(Data, secretKey); // Generate the signature

        QJsonObject requestObj; // Create a JSON object for the request
        requestObj["RequestSize"] = QString::number(Data.size()); // Add request size
        requestObj["RequestData"] = Data; // Add request data
        requestObj["Signature"] = signature; // Add signature

        QJsonDocument doc(requestObj); // Create a JSON document from the object
        QByteArray jsonData = doc.toJson(QJsonDocument::Compact); // Convert to compact JSON format

        qint32 jsonSize = jsonData.size(); // Get the size of the JSON data

        QByteArray header = QByteArray::number(jsonSize) + ":"; // Create the header with size and colon

        QByteArray frame = header + jsonData; // Construct the frame

        qDebug() << "User request frame:" << frame; // Debug output for the frame

        QByteArray encryptedData = encryptRequest(frame); // Encrypt the frame

        Socket.write(encryptedData); // Send the encrypted data

        emit UserSendRequest(encryptedData.toHex()); // Emit the signal with the encrypted data
    }
}

QByteArray User::encryptRequest(const QByteArray &request)
{
    QByteArray key = "1234567890123456"; // 128-bit key (16 bytes)
    QByteArray iv = "1234567890123456";  // 128-bit IV (16 bytes)
    QByteArray encryptedRequest = QAESEncryption::Crypt(QAESEncryption::AES_128, QAESEncryption::CBC, request, key, iv, QAESEncryption::PKCS7); // Encrypt the request
    return encryptedRequest; // Return the encrypted request
}

void User::onConnected()
{
    emit Connected(); // Emit the Connected signal
}

void User::onDisconnected()
{
    emit Disconnected(); // Emit the Disconnected signal
}

void User::onErrorOccurred(QAbstractSocket::SocketError socketError)
{
    emit ErrorOccurred(socketError); // Emit the ErrorOccurred signal with the socket error
}

void User::onStateChanged(QAbstractSocket::SocketState socketState)
{
    if (socketState == QAbstractSocket::UnconnectedState) // Check if the socket state is unconnected
    {
        Socket.close(); // Close the socket
    }
    emit StateChanged(socketState); // Emit the StateChanged signal with the socket state
}

void User::onReadyRead()
{
    QByteArray ByteArr = Socket.readAll(); // Read all available data from the socket

    int colonIndex = ByteArr.indexOf(':'); // Find the index of the colon separator
    if (colonIndex == -1) // Check if the colon is not found
    {
        qDebug() << "Invalid frame: no header separator found."; // Debug output for invalid frame
        return; // Exit the function
    }

    bool ok;
    int frameSize = QString(ByteArr.left(colonIndex)).toInt(&ok); // Extract and convert the frame size
    if (!ok || frameSize <= 0) // Check if the frame size is invalid
    {
        qDebug() << "Invalid frame: Invalid frame size."; // Debug output for invalid frame size
        return; // Exit the function
    }

    QByteArray jsonData = ByteArr.mid(colonIndex + 1); // Extract the JSON data
    if (jsonData.size() != frameSize) // Check if the JSON data size matches the frame size
    {
        qDebug() << "Invalid frame: Frame size does not match JSON data size."; // Debug output for size mismatch
        return; // Exit the function
    }

    QJsonDocument jsonDoc = QJsonDocument::fromJson(jsonData); // Parse the JSON data
    if (jsonDoc.isNull() || !jsonDoc.isObject()) // Check if the JSON data is invalid
    {
        qDebug() << "Invalid frame: Failed to parse JSON."; // Debug output for invalid JSON
        return; // Exit the function
    }

    QJsonObject jsonObj = jsonDoc.object(); // Get the JSON object
    QString responsesizeStr = jsonObj["ResponseSize"].toString(); // Extract the response size as a string
    int responseSize = responsesizeStr.toInt(&ok); // Convert the response size to an integer

    if (!ok || responseSize <= 0) // Check if the response size is invalid
    {
        qDebug() << (QString::number(responseSize)); // Debug output for response size
        qDebug() << "Invalid frame: Invalid response size."; // Debug output for invalid response size
        return; // Exit the function
    }

    QString responseData = jsonObj["ResponseData"].toString(); // Extract the response data
    if (responseData.size() != responseSize) // Check if the response data size matches the response size
    {
        qDebug() << "Invalid frame: Response size does not match actual data size."; // Debug output for size mismatch
        return; // Exit the function
    }
    emit ReadyRead(responseData); // Emit the ReadyRead signal with the response data
}
