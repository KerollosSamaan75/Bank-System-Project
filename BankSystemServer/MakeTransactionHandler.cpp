#include "MakeTransactionHandler.h"

MakeTransactionHandler::MakeTransactionHandler(BankDataBase &db) : dataBase(db) {}

void MakeTransactionHandler::execute(const QStringList &RequestParts, QString &statusMessage)
{
    if (RequestParts.size() < 3)
    {
        statusMessage = "Invalid request. Please provide account number and transaction amount.";
        return;
    }

    QString accountNumber = RequestParts[1];
    QString amount = RequestParts[2];

    // Validate the amount
    bool isNumber;
    int transactionAmount = amount.toInt(&isNumber);
    if (!isNumber)
    {
        statusMessage = "Invalid transaction amount.";
        return;
    }

    bool success = false;
    if (transactionAmount < 0)
    {
        QString withdrawAmount = amount.mid(1);  // Remove the negative sign for withdrawal
        success = dataBase.withdrawMoney(accountNumber, withdrawAmount);
    }
    else if (transactionAmount > 0)
    {
        success = dataBase.depositMoney(accountNumber, amount);
    }
    else
    {
        statusMessage = "Transaction amount cannot be zero.";
        return;
    }

    if (success)
    {
        statusMessage = "Transaction successful.";
        sendEmail(accountNumber, amount);
    }
    else
    {
        statusMessage = "Transaction failed.may be Insufficient balance";
    }
}

void MakeTransactionHandler::sendEmail(const QString &accountNumber, const QString &amountStr)
{
    // Construct email content
    QString subject = "Transaction Notification";
    QString body;

    if (amountStr.startsWith('-'))
    {
        body = QString("Dear User,You have withdrawn %1 L.E from your account.Best regards,IMT Bank").arg(amountStr.mid(1));  // Remove the negative sign for the email body
    }
    else
    {
        body = QString("Dear User,You have deposited %1 L.E into your account.Best regards,IMT Bank").arg(amountStr);
    }

    QString emailAddr = dataBase.getEmailByAccountNumber(accountNumber);

    // Send the email
    email.send(emailAddr, subject, body);
}
