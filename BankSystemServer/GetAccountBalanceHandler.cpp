#include "GetAccountBalanceHandler.h"

// Include the header file for GetAccountBalanceHandler class

GetAccountBalanceHandler::GetAccountBalanceHandler(BankDataBase &db) : dataBase(db) {}
// Constructor for GetAccountBalanceHandler class, initializing with a reference to BankDataBase instance

void GetAccountBalanceHandler::execute(const QStringList &RequestParts, QString &statusMessage)
{
    // Execute method that takes a QStringList RequestParts and QString statusMessage as parameters

    // Ensure RequestParts has the necessary elements
    if (RequestParts.size() < 2)
    {
        statusMessage = "Invalid request. Please provide the username or account number.";
        // If RequestParts does not contain at least two elements, set statusMessage to indicate invalid request
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
        // If client is found, set statusMessage to indicate the account balance for the user
    }
    else
    {
        statusMessage = QString("Client with account number %1 not found.").arg(accountNumber);
        // If client is not found, set statusMessage to indicate client not found with the account number
    }
}
