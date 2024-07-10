#include "SendEmail.h"

SendEmail::SendEmail() {}

void SendEmail::send(const QString &to, const QString &subject, const QString &body)
{
    // Check parameters for validity
    if (to.isEmpty() || subject.isEmpty() || body.isEmpty())
    {
        logger.logMessage("Error: Empty parameters detected. Cannot send email.");
        return;
    }

    QProcess process;

    // Path to your batch script
    QString batchFilePath = "D:/ITIDA_WorkSpace/Qt_Sessions/Final Project/BankSystemServer/sendEmail.bat";

    // Prepare arguments
    QStringList arguments;
    arguments << to << subject << body;

    // Start the batch script with arguments
    process.start(batchFilePath, arguments);
    if (!process.waitForFinished())
    {
        logger.logMessage(QString("Failed to run batch script: %1").arg(process.errorString()));
        return;
    }

    // Read and display the output or err
    QString error = process.readAllStandardError();
    if (!error.isEmpty())
    {
        logger.logMessage(QString("Error sending email: %1").arg(error));
    }
}



