#ifndef USER_H
#define USER_H

#include <QObject> // Include the QObject class
#include <QTcpSocket> // Include the QTcpSocket class for network communication
#include <QDebug> // Include QDebug for debugging output
#include <QMetaEnum> // Include QMetaEnum for meta-object system
#include <QJsonArray> // Include QJsonArray for JSON array handling
#include <QJsonDocument> // Include QJsonDocument for JSON document handling
#include <QJsonObject> // Include QJsonObject for JSON object handling
#include <QCryptographicHash> // Include QCryptographicHash for cryptographic hashing
#include <QProcessEnvironment> // Include QProcessEnvironment for environment variables
#include "qaesencryption.h" // Include custom AES encryption class

class User : public QObject // Define User class inheriting from QObject
{
    Q_OBJECT // Enable meta-object features like signals and slots
public:
    explicit User(QObject *parent = nullptr); // Constructor with optional parent parameter
    void ConnectToServer(QString Ip, qint32 Port); // Method to connect to server
    void DisconnectFromServer(); // Method to disconnect from server
    void SendRequest(QString Data); // Method to send request to server

signals:
    void Connected(); // Signal emitted when connected to server
    void Disconnected(); // Signal emitted when disconnected from server
    void ErrorOccurred(QAbstractSocket::SocketError socketError); // Signal emitted on socket error
    void StateChanged(QAbstractSocket::SocketState socketState); // Signal emitted on socket state change
    void ReadyRead(QString Data); // Signal emitted when data is ready to read
    void UserSendRequest(QString Data); // Signal emitted when user sends a request

private slots:
    void onConnected(); // Slot called when connected to server
    void onDisconnected(); // Slot called when disconnected from server
    void onErrorOccurred(QAbstractSocket::SocketError socketError); // Slot called on socket error
    void onStateChanged(QAbstractSocket::SocketState socketState); // Slot called on socket state change
    void onReadyRead(); // Slot called when data is ready to read

private:
    QString Ip; // IP address of the server
    qint32 Port; // Port number of the server
    QTcpSocket Socket; // TCP socket for network communication
    QByteArray encryptRequest(const QByteArray &request); // Method to encrypt request data
    QString generateSignature(const QString& message, const QString& secretKey); // Method to generate signature for a message
};

#endif // USER_H
