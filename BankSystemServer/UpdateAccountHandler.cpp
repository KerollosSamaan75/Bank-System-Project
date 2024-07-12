#include "UpdateAccountHandler.h"

UpdateAccountHandler::UpdateAccountHandler(BankDataBase &db) : dataBase(db) {}

void UpdateAccountHandler::execute(const QStringList &RequestParts, QString &statusMessage)
{
    // Ensure RequestParts has the necessary elements
    if (RequestParts.size() < 7)
    {
        statusMessage = "Invalid request. Please provide all required fields.";
        return;
    }

    QString fullName = RequestParts[1];
    QString userName = RequestParts[2];
    QString passWord = RequestParts[3];
    QString age = RequestParts[4];
    QString email = RequestParts[5];
    QString accountNumber = RequestParts[6];

    // Update the client account in the database
    bool success = dataBase.updateClient(accountNumber, userName, passWord, fullName, age, email);
    // Send appropriate response based on update result
    if (success)
    {
        statusMessage = "Account update successful.";
    }
    else
    {
        statusMessage = "Account update failed. Please check the account number and try again.";
    }
}
