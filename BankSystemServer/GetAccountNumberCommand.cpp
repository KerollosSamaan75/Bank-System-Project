#include "GetAccountNumberCommand.h"

GetAccountNumberCommand::GetAccountNumberCommand(BankDataBase &db) : dataBase(db) {}

void GetAccountNumberCommand::execute(const QStringList &RequestParts, QString &statusMessage)
{
    // Ensure RequestParts has the necessary elements
    if (RequestParts.size() < 2)
    {
        statusMessage = "Invalid request. Please provide username or identifier.";
        return;
    }

    QString username = RequestParts[1]; // Assuming username is in RequestParts[1]
    QVector<QJsonObject> databaseRecords = dataBase.getMainDatabase();

    // Search for the username in databaseRecords
    QString accountNumber;
    bool userFound = false;
    for (const auto& record : databaseRecords)
    {
        if (record["Username"].toString() == username)
        {
            accountNumber = record["AccountNumber"].toString(); // Adjust this based on your actual JSON structure
            userFound = true;
            break;
        }
    }

    // Check if the username was found
    if(userFound)
    {
        // Send the account number as a response
        statusMessage = QString("Account number for %1 is: %2").arg(username).arg(accountNumber);
    }
    else
    {
        // Send an error message if the username was not found
        statusMessage = QString("Account number for %1 not found.").arg(username);
    }
}
