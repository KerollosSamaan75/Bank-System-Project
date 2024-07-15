#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include <QTextStream>
#include <QDebug>
#include <ServerHandler.h>
#include "Logger.h"

// The Server class inherits QTcpServer and handles incoming client connections.
// It starts a TCP server and manages incoming connections by spawning ServerHandler instances.

class Server : public QTcpServer
{
    Q_OBJECT
public:
    // Constructor: Initializes an instance of Server.
    explicit Server(QObject *parent = nullptr);

    // StartServer method starts the TCP server.
    void StartServer();

signals:

protected:
    // Override of QTcpServer's incomingConnection method.
    // Handles incoming client connections by spawning ServerHandler instances.
    void incomingConnection(qintptr handle) override;

private:
    qint32 Port;     // Port number on which the server listens for incoming connections.
    Logger logger;   // Logger instance for logging server operations.
};

#endif // SERVER_H
