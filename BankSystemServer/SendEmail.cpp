#include "SendEmail.h" // Include the header file for SendEmail

SendEmail::SendEmail() {} // Constructor definition for SendEmail

void SendEmail::send(const QString &to, const QString &subject, const QString &body)
{
    // Check parameters for validity
    if (to.isEmpty() || subject.isEmpty() || body.isEmpty())
    {
        logger.logMessage("Error: Empty parameters detected. Cannot send email."); // Log an error if any parameter is empty
        return;
    }

    QProcess process; // Create a QProcess object to run external processes

    // Path to your batch script
    QString batchFilePath = "..\\..\\sendEmail.bat"; // Specify the path to the batch file for sending emails

    // Prepare arguments
    QStringList arguments;
    arguments << to << subject << body; // Prepare arguments for the batch script (recipient email, subject, body)

    // Start the batch script with arguments
    process.startDetached(batchFilePath, arguments); // Start the batch script with specified arguments
    if (!process.waitForFinished())
    {
        logger.logMessage(QString("Failed to run batch script: %1").arg(process.errorString())); // Log an error if the batch script fails to execute
        return;
    }

    // Read and display the output or err
    QString error = process.readAllStandardError(); // Read standard error output from the process
    if (!error.isEmpty())
    {
        logger.logMessage(QString("Error sending email: %1").arg(error)); // Log an error if there is any error output from the process
    }
}
