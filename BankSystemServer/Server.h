#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include<QTcpServer>
#include<QTextStream>
#include<QDebug>
#include<ServerHandler.h>

class Server : public QTcpServer
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);
    void StartServer();
signals:

    // QTcpServer interface
protected:
    void incomingConnection(qintptr handle) override;
private:
    QTextStream qin;
    QTextStream qout;
    qint32 Port;
    //DataBase _dataBase;
};
#endif // SERVER_H
