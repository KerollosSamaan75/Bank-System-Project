#ifndef USER_H
#define USER_H

#include <QObject>
#include<QTcpSocket>
#include<QDebug>
#include<QMetaEnum>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QCryptographicHash>
#include <QProcessEnvironment>
#include "qaesencryption.h"

class User : public QObject
{
    Q_OBJECT
public:
    explicit User(QObject *parent = nullptr);
    void ConnectToServer(QString Ip,qint32 Port);
    void DisconnectFromServer();
    void SendRequest(QString Data);


signals:
    void Connected();
    void Disconnected();
    void ErrorOccurred(QAbstractSocket::SocketError socketError);
    void StateChanged(QAbstractSocket::SocketState socketState);
    void ReadyRead(QString Data);
    void UserSendRequest(QString Data);

private slots:
    void onConnected();
    void onDisconnected();
    void onErrorOccurred(QAbstractSocket::SocketError socketError);
    void onStateChanged(QAbstractSocket::SocketState socketState);
    void onReadyRead();

private:
    QString Ip;
    qint32 Port;
    QTcpSocket Socket;
    QByteArray encryptRequest(const QByteArray &request);
    QString generateSignature(const QString& message, const QString& secretKey);
};

#endif // USER_H
