// Logger.h
#ifndef LOGGER_H
#define LOGGER_H

#include <QString>

class Logger
{
public:
    static Logger& instance();
    void logMessage(const QString &message);

private:
    Logger(); // Private constructor for singleton pattern
    ~Logger();
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
};

#endif // LOGGER_H
