// Logger.h
#ifndef LOGGER_H
#define LOGGER_H

#include <QString>

class Logger
{
public:
    Logger();
    ~Logger();
    void logMessage(const QString &message);
};

#endif // LOGGER_H
