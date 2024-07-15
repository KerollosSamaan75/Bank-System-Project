#ifndef SENDEMAIL_H
#define SENDEMAIL_H

#include <QString>
#include <QProcess>
#include <QDebug>
#include "Logger.h"

// The SendEmail class provides functionality to send email notifications.
// It uses QProcess to invoke the email sending command-line tool and logs operations using the Logger.

class SendEmail
{
public:
    // Constructor: Initializes an instance of SendEmail.
    SendEmail();

    // send method sends an email with specified parameters.
    // Parameters:
    // - to: The recipient email address.
    // - subject: The subject of the email.
    // - body: The body content of the email.
    void send(const QString &to, const QString &subject, const QString &body);

private:
    QString to;         // The recipient email address.
    QString subject;    // The subject of the email.
    QString body;       // The body content of the email.
    Logger logger;      // Logger instance for logging email sending operations.
};

#endif // SENDEMAIL_H
