#include "GetAccountBalanceCommand.h"

GetAccountBalanceCommand::GetAccountBalanceCommand(BankDataBase &db) : dataBase(db) {}

void GetAccountBalanceCommand::execute(const QStringList &RequestParts, QString &statusMessage)
{
    // Ensure RequestParts has the necessary elements
    if (RequestParts.size() < 2)
    {
        statusMessage ="Invalid request. Please provide the username or account number.";
        return;
    }

    QString accountNumber = RequestParts[1]; // Assuming the identifier (account number) is in RequestParts[1]
    QVector<QJsonObject> databaseRecords = dataBase.getMainDatabase(); // Get the main database records

    // Flag to check if client is found
    bool clientFound = false;
    QString balance;
    QString userName;

    // Loop through each record in the database
    for (const auto& record : databaseRecords)
    {
        if (record["AccountNumber"].toString() == accountNumber)
        {
            balance = record["Balance"].toString();
            userName = record["Username"].toString();
            clientFound = true;
            break;
        }
    }

    if (clientFound)
    {
        statusMessage = QString("The account balance for %1 is %2.").arg(userName, balance);
    }
    else
    {
        statusMessage = QString("Client with account number %1 not found.").arg(accountNumber);
    }
}
