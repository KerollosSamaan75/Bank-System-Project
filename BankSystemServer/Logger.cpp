// Logger.cpp
#include "Logger.h"
#include <QFile>
#include <QTextStream>
#include <QDateTime>
#include <QDebug>

Logger::Logger(){}
Logger::~Logger(){}

void Logger::logMessage(const QString &message)
{
    QFile file("Serverlog.log");  // Specify the log file path
    if (file.open(QIODevice::Append | QIODevice::Text))
    {
        QTextStream out(&file);
        out << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") << " - " << message << "\n";
        file.close();
    }
    else
    {
        qDebug()<<"Error:Serverlog.txt Cannot open or not found"<<Qt::endl;
    }
}
