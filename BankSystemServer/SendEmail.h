#ifndef SENDEMAIL_H
#define SENDEMAIL_H

#include <QString>
#include <QProcess>
#include <QDebug>
#include "Logger.h"

class SendEmail
{
public:
    SendEmail();
    void send(const QString &to, const QString &subject, const QString &body);
private:
    QString to;
    QString subject;
    QString body;
    Logger logger;
};

#endif // SENDEMAIL_H
