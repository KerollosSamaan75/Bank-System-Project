// Logger.cpp
#include "Logger.h"
#include <QFile>
#include <QTextStream>
#include <QDateTime>

Logger::Logger(){}

Logger::~Logger(){}

Logger& Logger::instance()
{
    static Logger instance;
    return instance;
}

void Logger::logMessage(const QString &message)
{
    QFile file("log.txt");  // Specify the log file path
    if (file.open(QIODevice::Append | QIODevice::Text))
    {
        QTextStream out(&file);
        out << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") << " - " << message << "\n";
        file.close();
    }
}
