// Command.h
#ifndef COMMAND_H
#define COMMAND_H

#include <QStringList>
#include <QString>

class Command {
public:
    virtual ~Command() = default;
    virtual void execute(const QStringList &RequestParts, QString &statusMessage) = 0;
};

#endif // COMMAND_H
