#include "MakeTransferHandler.h" // Include the header file for MakeTransferHandler

MakeTransferHandler::MakeTransferHandler(BankDataBase &db) : dataBase(db) {} // Constructor initialization for MakeTransferHandler

void MakeTransferHandler::execute(const QStringList &RequestParts, QString &statusMessage)
{
    if (RequestParts.size() != 4)
    {
        statusMessage = "Invalid request."; // Check if the request contains exactly 4 parts
    }

    QString sourceAccountNumber = RequestParts[1]; // Extract source account number from RequestParts
    QString targetAccountNumber = RequestParts[2]; // Extract target account number from RequestParts
    QString amountStr = RequestParts[3]; // Extract transfer amount from RequestParts

    // Ensure source and target account numbers are not the same
    if (sourceAccountNumber == targetAccountNumber)
    {
        statusMessage = "Source and target account numbers cannot be the same."; // Prevent transfer between same accounts
        return;
    }

    bool isNumber;
    int amount = amountStr.toInt(&isNumber); // Convert amount to integer
    if (!isNumber || amount <= 0)
    {
        statusMessage = "Invalid transfer amount."; // Handle invalid transfer amount
        return;
    }

    QVector<QJsonObject> databaseRecords = dataBase.getMainDatabase(); // Get the main database records
    bool sourceFound = false;
    bool targetFound = false;
    for (const auto& record : databaseRecords)
    {
        if (record["AccountNumber"].toString() == sourceAccountNumber)
        {
            sourceFound = true;
            break;
        }
    }
    for (const auto& record : databaseRecords)
    {
        if (record["AccountNumber"].toString() == targetAccountNumber)
        {
            targetFound = true;
            break;
        }
    }
    if(sourceFound)
    {
        if(targetFound)
        {
            bool success = dataBase.transferMoney(sourceAccountNumber, targetAccountNumber, amountStr); // Perform money transfer

            if (success)
            {
                statusMessage = QString("TransferResult:Transfer successful."); // Update status message for successful transfer
                sendEmail(sourceAccountNumber, targetAccountNumber, amountStr); // Send email notifications
            }
            else
            {
                statusMessage = QString("TransferResult:Transfer failure.\nInsufficient balance"); // Handle transfer failure
                return;
            }
        }
        else
        {
            statusMessage = "Target account number not found";
            return;
        }

    }
    else
    {
        statusMessage = "Source account number not found";
        return;
    }
}

void MakeTransferHandler::sendEmail(const QString &sourceAccountNumber, const QString &targetAccountNumber, const QString &amountStr)
{
    // Construct email content
    QString subject = "Transaction Notification";
    QString sourceBody = QString("Dear User, You have transferred %1 L.E to account %2. Best regards, IMT Bank").arg(amountStr).arg(targetAccountNumber); // Email body for source account
    QString targetBody = QString("Dear User, You have received %1 L.E from account %2. Best regards, IMT Bank").arg(amountStr).arg(sourceAccountNumber); // Email body for target account

    // Retrieve email addresses from the database
    QString sourceEmail = dataBase.getEmailByAccountNumber(sourceAccountNumber); // Get source account email
    QString targetEmail = dataBase.getEmailByAccountNumber(targetAccountNumber); // Get target account email

    // Send emails
    email.send(sourceEmail, subject, sourceBody); // Send email to source account holder
    email.send(targetEmail, subject, targetBody); // Send email to target account holder
}
