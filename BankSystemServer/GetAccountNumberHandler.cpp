#include "GetAccountNumberHandler.h"

// Include the header file for GetAccountNumberHandler class

GetAccountNumberHandler::GetAccountNumberHandler(BankDataBase &db) : dataBase(db) {}
// Constructor for GetAccountNumberHandler class, initializing with a reference to BankDataBase instance

void GetAccountNumberHandler::execute(const QStringList &RequestParts, QString &statusMessage)
{
    // Execute method that takes a QStringList RequestParts and QString statusMessage as parameters

    // Ensure RequestParts has the necessary elements
    if (RequestParts.size() < 2)
    {
        statusMessage = "Invalid request. Please provide username or identifier.";
        // If RequestParts does not contain at least two elements, set statusMessage to indicate invalid request
        return;
    }

    QString username = RequestParts[1]; // Assuming username is in RequestParts[1]
    QVector<QJsonObject> databaseRecords = dataBase.getMainDatabase(); // Get the main database records

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
        // If username is found, set statusMessage to indicate the account number associated with the username
    }
    else
    {
        // Send an error message if the username was not found
        statusMessage = QString("Account number for %1 not found.").arg(username);
        // If username is not found, set statusMessage to indicate that the account number was not found
    }
}
