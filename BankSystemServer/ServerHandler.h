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
#include "qaesencryption.h"

class ServerHandler : public QThread
{
    Q_OBJECT
public:
    explicit ServerHandler(qint32 ID, QObject *parent = nullptr);

public slots:
    void onReadyRead();
    void onDisconnected();

protected:
    void run() override;

private:
    qint32 userID;
    QTcpSocket *Socket;
    BankDataBase dataBase;
    QString statusMessage;
    QMap<QString, Command*> commandMap;
    void setupCommands();
    void Operation(QString Request);
    void sendResponse(const QString &Message);
    QByteArray decryptRequest(const QByteArray &encryptedData);
};

#endif // SERVERHANDLER_H
