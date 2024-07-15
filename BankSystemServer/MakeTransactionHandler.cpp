#include "MakeTransactionHandler.h" // Include the header file for MakeTransactionHandler

MakeTransactionHandler::MakeTransactionHandler(BankDataBase &db) : dataBase(db) {} // Constructor initialization for MakeTransactionHandler

void MakeTransactionHandler::execute(const QStringList &RequestParts, QString &statusMessage)
{
    if (RequestParts.size() < 3)
    {
        statusMessage = "Invalid request. Please provide account number and transaction amount."; // Check if enough parameters are provided
        return;
    }

    QString accountNumber = RequestParts[1]; // Extract account number from RequestParts
    QString amount = RequestParts[2]; // Extract transaction amount from RequestParts

    // Validate the amount
    bool isNumber;
    int transactionAmount = amount.toInt(&isNumber); // Convert amount to integer
    if (!isNumber)
    {
        statusMessage = "Invalid transaction amount."; // Handle invalid amount
        return;
    }

    bool success = false;
    if (transactionAmount < 0)
    {
        QString withdrawAmount = amount.mid(1); // Remove the negative sign for withdrawal
        success = dataBase.withdrawMoney(accountNumber, withdrawAmount); // Withdraw money from the account
    }
    else if (transactionAmount > 0)
    {
        success = dataBase.depositMoney(accountNumber, amount); // Deposit money into the account
    }
    else
    {
        statusMessage = "Transaction amount cannot be zero."; // Zero transaction amount not allowed
        return;
    }

    if (success)
    {
        statusMessage = "Transaction successful."; // Update status message for successful transaction
        sendEmail(accountNumber, amount); // Send transaction notification email
    }
    else
    {
        statusMessage = "Transaction failed. Insufficient balance."; // Handle failed transaction due to insufficient balance
    }
}

void MakeTransactionHandler::sendEmail(const QString &accountNumber, const QString &amountStr)
{
    // Construct email content
    QString subject = "Transaction Notification";
    QString body;

    if (amountStr.startsWith('-'))
    {
        body = QString("Dear User, You have withdrawn %1 L.E from your account. Best regards, IMT Bank").arg(amountStr.mid(1)); // Remove the negative sign for withdrawal email notification
    }
    else
    {
        body = QString("Dear User, You have deposited %1 L.E into your account. Best regards, IMT Bank").arg(amountStr); // Deposit email notification
    }

    QString emailAddr = dataBase.getEmailByAccountNumber(accountNumber); // Get email address associated with the account

    // Send the email
    email.send(emailAddr, subject, body); // Call function to send email notification
}
