#include "MakeTransactionCommand.h"

MakeTransactionCommand::MakeTransactionCommand(BankDataBase &db) : dataBase(db) {}

void MakeTransactionCommand::execute(const QStringList &RequestParts, QString &statusMessage)
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

    bool success;
    if (transactionAmount < 0)
    {
        QString withdrawAmount = amount.mid(1);
        success = dataBase.withdrawMoney(accountNumber, withdrawAmount, statusMessage);
        Logger::instance().logMessage(statusMessage);
    }
    else if (transactionAmount > 0)
    {
        success = dataBase.depositMoney(accountNumber, amount, statusMessage);
        Logger::instance().logMessage(statusMessage);
    }
    else
    {
        statusMessage = "Transaction amount cannot be zero.";
        return;
    }

    if (success)
    {
        statusMessage = ("Transaction successful: " + statusMessage);
    }
    else
    {
        statusMessage = ("Transaction failed: " + statusMessage);
    }
}
