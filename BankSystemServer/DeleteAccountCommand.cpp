#include "DeleteAccountCommand.h"

DeleteAccountCommand::DeleteAccountCommand(BankDataBase &db) : dataBase(db) {}

void DeleteAccountCommand::execute(const QStringList &RequestParts, QString &statusMessage)
{
    // Ensure RequestParts has the necessary elements
    if (RequestParts.size() < 2)
    {
        statusMessage = "Invalid request. Please provide the account number.";
        return;
    }
    QString accountNumber = RequestParts[1]; // Assuming account number is in RequestParts[1]

    // Attempt to delete the client from the database
    bool success = dataBase.deleteClient(accountNumber);
    if (success)
    {
        statusMessage = QString("Client account with account number %1 has been successfully deleted.").arg(accountNumber);
    }
    else
    {   statusMessage = QString("Failed to delete client account with account number %1. The account may not exist.").arg(accountNumber);
    }
}
