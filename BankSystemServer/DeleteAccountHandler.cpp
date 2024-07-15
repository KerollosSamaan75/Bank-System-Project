#include "DeleteAccountHandler.h"

// Include the header file for DeleteAccountHandler class

DeleteAccountHandler::DeleteAccountHandler(BankDataBase &db) : dataBase(db) {}
// Constructor for DeleteAccountHandler class, initializing with a reference to BankDataBase instance

void DeleteAccountHandler::execute(const QStringList &RequestParts, QString &statusMessage)
{
    // Execute method that takes a QStringList RequestParts and QString statusMessage as parameters

    // Ensure RequestParts has the necessary elements
    if (RequestParts.size() < 2)
    {
        statusMessage = "Invalid request. Please provide the account number.";
        // If RequestParts does not contain at least two elements, set statusMessage to indicate invalid request
        return;
    }
    QString accountNumber = RequestParts[1]; // Assuming account number is in RequestParts[1]
    // Extract the account number from RequestParts and store it in QString accountNumber

    // Attempt to delete the client from the database
    bool success = dataBase.deleteClient(accountNumber);
    // Call deleteClient method on dataBase (BankDataBase instance) with accountNumber as parameter, store success status

    if (success)
    {
        statusMessage = QString("Client account with account number %1 has been successfully deleted.").arg(accountNumber);
        // If deletion is successful, set statusMessage to indicate successful deletion with the account number
    }
    else
    {
        statusMessage = QString("Failed to delete client account with account number %1. The account may not exist.").arg(accountNumber);
        // If deletion fails, set statusMessage to indicate failure with the account number
    }
}
