// Logger.cpp
#include "Logger.h"
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QDebug>

Logger::Logger() {} // Constructor for Logger class
Logger::~Logger() {} // Destructor for Logger class

void Logger::logMessage(const QString &message)
{
    QFile file("D:\\ITIDA_WorkSpace\\Qt_Sessions\\Final Project\\BankSystemServer\\Serverlog.log");  // Specify the log file path
    if (file.open(QIODevice::Append | QIODevice::Text))
    {
        QTextStream out(&file); // QTextStream object for writing to the file
        out << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") << " - " << message << "\n";
        // Write current date and time, along with the log message, to the file
        file.close(); // Close the file after writing
    }
    else
    {
        qDebug() << "Error: Serverlog.txt Cannot open or not found" << Qt::endl;
        // Output debug message if the log file cannot be opened
    }
}
