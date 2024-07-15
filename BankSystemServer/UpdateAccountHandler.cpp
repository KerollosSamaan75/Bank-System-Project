#include "UpdateAccountHandler.h" // Include the header file for UpdateAccountHandler

UpdateAccountHandler::UpdateAccountHandler(BankDataBase &db) : dataBase(db) {} // Constructor initializing the database reference

void UpdateAccountHandler::execute(const QStringList &RequestParts, QString &statusMessage)
{
    // Ensure RequestParts has the necessary elements
    if (RequestParts.size() < 7)
    {
        statusMessage = "Invalid request. Please provide all required fields."; // Inform about invalid request if fields are missing
        return;
    }

    QString fullName = RequestParts[1]; // Extract full name from request parts
    QString userName = RequestParts[2]; // Extract username from request parts
    QString passWord = RequestParts[3]; // Extract password from request parts
    QString age = RequestParts[4]; // Extract age from request parts
    QString email = RequestParts[5]; // Extract email from request parts
    QString accountNumber = RequestParts[6]; // Extract account number from request parts

    // Update the client account in the database
    bool success = dataBase.updateClient(accountNumber, userName, passWord, fullName, age, email); // Update client account in the database

    // Send appropriate response based on update result
    if (success)
    {
        statusMessage = "Account update successful."; // Set success message if account update is successful
    }
    else
    {
        statusMessage = "Account update failed. Please check the account number and try again."; // Set failure message if account update fails
    }
}
