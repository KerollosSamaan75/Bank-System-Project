#ifndef USER_H
#define USER_H

#include <QObject>
#include<QTcpSocket>
#include<QDebug>
#include<QMetaEnum>

class User : public QObject
{
    Q_OBJECT
public:
    explicit User(QObject *parent = nullptr);
    void ConnectToDevice(QString Ip,qint32 Port);
    void DisconnectFromDevice();
    void WriteData(QString Data);
signals:
    void Connected();
    void Disconnected();
    void ErrorOccurred(QAbstractSocket::SocketError socketError);
    void StateChanged(QAbstractSocket::SocketState socketState);
    void ReadyRead(QString Data);
    void UserWriteData(QString Data);

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
};

#endif // USER_H
