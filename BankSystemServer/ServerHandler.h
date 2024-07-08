#ifndef SERVERHANDLER_H
#define SERVERHANDLER_H

#include <QObject>
#include <QThread>
#include <QTcpSocket>
#include <QDebug>
#include <QString>
#include <QMap>
#include "BankDataBase.h"
#include "Logger.h"
#include "Command.h"
#include "LoginCommand.h"
#include "AddClientCommand.h"
#include "DeleteAccountCommand.h"
#include "GetAccountBalanceCommand.h"
#include "GetAccountNumberCommand.h"
#include "GetTransactionHistoryCommand.h"
#include "MakeTransactionCommand.h"
#include "MakeTransferCommand.h"
#include "UpdateAccountCommand.h"
#include "GetBankDataBaseCommand.h"

class ServerHandler : public QThread
{
    Q_OBJECT
public:
    explicit ServerHandler(qint32 ID, QObject *parent = nullptr);
    void sendMessage(const QString &Message);
    void Operation(QString Request);

signals:

private:
    qint32 ID;
    QTcpSocket *Socket;
    BankDataBase dataBase;
    QString statusMessage;
    QMap<QString, Command*> commandMap;

protected:
    void run() override;

public slots:
    void onReadyRead();
    void onDisconnected();

private:
    void setupCommands();
};

#endif // SERVERHANDLER_H
