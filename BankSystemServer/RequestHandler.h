#ifndef REQUESTHANDLER_H
#define REQUESTHANDLER_H

#include <QStringList>
#include <QString>

// The RequestHandler class is an abstract base class for handling requests.
// Subclasses must override the execute method to define specific request handling logic.

class RequestHandler {
public:
    // Virtual destructor ensures proper cleanup of derived classes.
    virtual ~RequestHandler() = default;

    // Pure virtual function to execute a request.
    // Parameters:
    // - RequestParts: A QStringList containing parsed parts of the request.
    // - statusMessage: A QString reference to update with the execution status or response.
    virtual void execute(const QStringList &RequestParts, QString &statusMessage) = 0;
};

#endif // REQUESTHANDLER_H
