#ifndef LOGGER_H
#define LOGGER_H

#include <QString>

// The Logger class provides functionality to log messages.
// It allows other classes and components to log messages to a specified output.
class Logger
{
public:
    // Constructor: Initializes the Logger instance.
    Logger();

    // Destructor: Cleans up resources used by the Logger instance.
    ~Logger();

    // logMessage method logs a message to the logger.
    // Parameters:
    // - message: The message to be logged, provided as a QString.
    void logMessage(const QString &message);
};

#endif // LOGGER_H
