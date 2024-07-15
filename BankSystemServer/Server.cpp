#include "Server.h" // Include the header file for Server

Server::Server(QObject *parent) : QTcpServer{parent} {} // Constructor definition for Server, inheriting QTcpServer

void Server::StartServer()
{
    Port = 1234; // Set the port number for the server
    this->listen(QHostAddress::Any, Port); // Start listening on any IP address on the specified port

    if (isListening())
    {
        QString logMessage = QString("Server is up and listening to port => %1").arg(Port); // Log message indicating server is listening
        logger.logMessage(logMessage); // Log the message using the logger object
        qDebug() << logMessage; // Output the message to qDebug for debugging
    }
    else
    {
        QString logMessage = QString("Server can't listen to port => %1").arg(Port); // Log message indicating server failed to start listening
        logger.logMessage(logMessage); // Log the message using the logger object
        qDebug() << logMessage; // Output the message to qDebug for debugging
    }
}

void Server::incomingConnection(qintptr handle)
{
    QString logMessage = QString("User:%1 connent to server").arg(handle); // Log message indicating incoming connection
    logger.logMessage(logMessage); // Log the message using the logger object
    qDebug() << logMessage; // Output the message to qDebug for debugging

    ServerHandler* serverhandler = new ServerHandler(handle); // Create a new ServerHandler object for handling the incoming connection
    connect(serverhandler, &QThread::finished, serverhandler, &QThread::deleteLater); // Connect signals to ensure proper cleanup of ServerHandler
    serverhandler->start(); // Start the ServerHandler thread to handle the incoming connection
}
