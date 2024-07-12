#include "MakeTransferHandler.h"

MakeTransferHandler::MakeTransferHandler(BankDataBase &db) : dataBase(db) {}

void MakeTransferHandler::execute(const QStringList &RequestParts, QString &statusMessage)
{
    if (RequestParts.size() != 4)
    {
        statusMessage = "Invalid request.";
    }

    QString sourceAccountNumber = RequestParts[1];
    QString targetAccountNumber = RequestParts[2];
    QString amountStr = RequestParts[3];

    // Validate that the account numbers are digits only
    QRegularExpression accountNumberRegex("^\\d+$");
    if (!accountNumberRegex.match(sourceAccountNumber).hasMatch() || !accountNumberRegex.match(targetAccountNumber).hasMatch())
    {
        statusMessage = "Invalid account number format.";
        return;
    }

    // Validate the amount
    bool isNumber;
    int amount = amountStr.toInt(&isNumber);
    if (!isNumber || amount <= 0)
    {
        statusMessage = "Invalid transfer amount.";
        return;
    }

    // Ensure source and target account numbers are not the same
    if (sourceAccountNumber == targetAccountNumber)
    {
        statusMessage ="Source and target account numbers cannot be the same.";
        return;
    }

    bool success = dataBase.transferMoney(sourceAccountNumber, targetAccountNumber,amountStr);


    if (success)
    {
        statusMessage = QString("TransferResult:Transfer successful.");
        sendEmail(sourceAccountNumber,targetAccountNumber,amountStr);
    }
    else
    {
        statusMessage = QString("TransferResult:Transfer failure.may be Insufficient balance");
    }

}

void MakeTransferHandler::sendEmail(const QString &sourceAccountNumber, const QString &targetAccountNumber, const QString &amountStr)
{
    // Construct email content
    QString subject = "Transaction Notification";
    QString sourceBody = QString("Dear User,You have transferred %1 L.E to account %2.Best regards,IMT Bank").arg(amountStr).arg(targetAccountNumber);
    QString targetBody = QString("Dear User,You have received %1 L.E from account %2.Best regards,IMT Bank").arg(amountStr).arg(sourceAccountNumber);

    // Retrieve email addresses from the database
    QString sourceEmail = dataBase.getEmailByAccountNumber(sourceAccountNumber);
    QString targetEmail = dataBase.getEmailByAccountNumber(targetAccountNumber);

    // Send emails
    email.send(sourceEmail, subject, sourceBody);
    email.send(targetEmail, subject, targetBody);
}


