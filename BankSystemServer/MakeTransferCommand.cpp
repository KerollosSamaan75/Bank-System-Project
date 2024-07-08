#include "MakeTransferCommand.h"

MakeTransferCommand::MakeTransferCommand(BankDataBase &db) : dataBase(db) {}

void MakeTransferCommand::execute(const QStringList &RequestParts, QString &statusMessage)
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

    bool success = dataBase.transferMoney(sourceAccountNumber, targetAccountNumber,amountStr,amountStr, statusMessage);


    if (success)
    {
        statusMessage = QString("TransferResult:%1").arg(statusMessage);
    }
    else
    {
        statusMessage = QString("TransferResult:%1").arg(statusMessage);
    }

}
