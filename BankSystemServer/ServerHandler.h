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
#include "RequestHandler.h"
#include "LoginHandler.h"
#include "AddClientHandler.h"
#include "DeleteAccountHandler.h"
#include "GetAccountBalanceHandler.h"
#include "GetAccountNumberHandler.h"
#include "GetTransactionHistoryHandler.h"
#include "MakeTransactionHandler.h"
#include "MakeTransferHandler.h"
#include "UpdateAccountHandler.h"
#include "GetBankDataBaseHandler.h"
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
    QString loginUser;
    bool loginStatus;
    Logger logger;
    QMap<QString, RequestHandler*> requestHandlerMap;
    void setupRequestHandles();
    void Operation(QString Request);
    void sendResponse(const QString &Message);
    QByteArray decryptRequest(const QByteArray &encryptedData);
};

#endif // SERVERHANDLER_H
