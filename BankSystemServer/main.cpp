#include <QCoreApplication> // Include the Qt core application header

#include "Server.h" // Include your Server class header file

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv); // Create a Qt application instance

    Server MyServer; // Create an instance of your Server class

    MyServer.StartServer(); // Call the StartServer method of your Server instance to start the server

    return a.exec(); // Start the Qt event loop and run the application
}
