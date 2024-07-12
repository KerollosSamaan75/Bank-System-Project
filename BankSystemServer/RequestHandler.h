// Command.h
#ifndef REQUESTHANDLER_H
#define REQUESTHANDLER_H

#include <QStringList>
#include <QString>

class RequestHandler {
public:
    virtual ~RequestHandler() = default;
    virtual void execute(const QStringList &RequestParts, QString &statusMessage) = 0;
};

#endif // REQUESTHANDLER_H
