#ifndef SERVERHANDLER_H
#define SERVERHANDLER_H

#include <QObject>
#include<QThread>
#include<QTcpSocket>
#include<QDebug>
#include<QString>
#include"BankDataBase.h"
class ServerHandler : public QThread
{
    Q_OBJECT
public:
    explicit ServerHandler(qint32 ID,QObject *parent = nullptr);
    //~ServerHandler();
    void sendMessage(QString Message);
    void Operation(QString Request);
    void loginToServer(const QStringList& RequestParts);
    void addNewClient(const QStringList& RequestParts);
    void getClientAccountNumber(const QStringList& RequestParts);
    void deleteClientAccount(const QStringList& RequestParts);
    void getClientAccountBalance(const QStringList& RequestParts);
    void getClientTransactionHistory(const QStringList& RequestParts);
    void getBankDataBase(const QStringList& RequestParts);
    void updateClientAccount(const QStringList& RequestParts);
    void makeTransaction(const QStringList& RequestParts);
signals:

private:
    qint32 ID;
    QTcpSocket* Socket;
    BankDataBase dataBase;
    QString userName;
    QString password;
    // QThread interface
protected:
    void run() override;

public slots:
    void onReadyRead();
    void onDisconnected();

};

#endif // SERVERHANDLER_H
