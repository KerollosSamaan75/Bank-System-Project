#include <QCoreApplication>
#include"Server.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Server MyServer;
    MyServer.StartServer();
    return a.exec();
}
