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
#include "LogoutHandler.h"
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

// The ServerHandler class manages individual client connections in a multithreaded TCP server application.
// It handles client requests, delegates them to appropriate handlers, and manages server-side operations.

class ServerHandler : public QThread
{
    Q_OBJECT
public:
    // Constructor: Initializes an instance of ServerHandler.
    // Parameters:
    // - ID: Unique identifier for the client connection.
    // - parent: Optional parent object.
    explicit ServerHandler(qint32 ID, QObject *parent = nullptr);

public slots:
    // Slot: Triggered when data is ready to be read from the socket.
    void onReadyRead();

    // Slot: Triggered when the client disconnects from the server.
    void onDisconnected();

protected:
    // Override of QThread's run method.
    // Manages the main execution logic of the server handler.
    void run() override;

private:
    qint32 userID;                           // Unique identifier for the client connection.
    QTcpSocket *Socket;                      // Socket for communication with the client.
    BankDataBase dataBase;                   // Database instance for managing client data.
    QString statusMessage;                   // Status message to communicate with clients.
    QString loginUser;                       // Logged-in user's username.
    bool loginStatus;                        // Flag indicating login status.
    Logger logger;                           // Logger instance for logging server operations.
    QMap<QString, RequestHandler*> requestHandlerMap; // Map of request handlers for different types of requests.

    // Initializes request handlers for various client requests.
    void setupRequestHandles();

    // Processes a client request.
    // Parameters:
    // - Request: The request received from the client.
    void Operation(QString Request);

    // Sends a response message to the client.
    // Parameters:
    // - Message: The message to send as a response.
    void sendResponse(const QString &Message);

    // Decrypts incoming encrypted data from the client.
    // Parameters:
    // - encryptedData: Encrypted data received from the client.
    // Returns:
    // Decrypted data as QByteArray.
    QByteArray decryptRequest(const QByteArray &encryptedData);
};

#endif // SERVERHANDLER_H
