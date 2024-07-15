// LoginCommand.cpp
#include "LoginHandler.h"

// Constructor for LoginHandler, initializing with a reference to BankDataBase
LoginHandler::LoginHandler(BankDataBase &db) : dataBase(db) {}

// Execute function implementation, handling login requests
void LoginHandler::execute(const QStringList &RequestParts, QString &statusMessage)
{
    // Ensure RequestParts has at least 3 elements
    if (RequestParts.size() < 3)
    {
        statusMessage = "Invalid request. Please provide username and password.";
        return;
    }

    const QString userName = RequestParts[1]; // Extract username from RequestParts
    const QString passWord = RequestParts[2]; // Extract password from RequestParts
    bool isUserValid = false; // Flag to track if user is valid
    QString userAuthority; // Variable to store user authority level
    QString userAccountNumber; // Variable to store user account number
    QVector<QJsonObject> databaseRecords = dataBase.getMainDatabase(); // Retrieve main database records

    // Loop through each record in the database
    for (const auto& record : databaseRecords)
    {
        // Check if username and password match
        if (record["Username"].toString() == userName && record["Password"].toString() == passWord)
        {
            // Check if the user is not already logged in
            if (record["Login"].toString() == "0")
            {
                isUserValid = true; // Mark user as valid
                userAuthority = record["Authority"].toString(); // Capture user authority
                userAccountNumber = record["AccountNumber"].toString(); // Capture user account number
                break; // Exit loop as user is found
            }
            else
            {
                statusMessage = "Login failed. This account is already logged in.";
                return; // Exit function as login is not possible
            }
        }
    }

    // Process based on whether user is valid or not
    if (isUserValid)
    {
        // Change the 'log' state in the database
        if (dataBase.setUserLoginState(userName, "1"))
        {
            // Prepare success message with user authority, username, and account number
            QString successMessage = QString("%1:%2:%3").arg(userAuthority, userName, userAccountNumber);
            statusMessage = successMessage; // Set status message to success message
        }
        else
        {
            statusMessage = "Login failed. Could not update the login state."; // Error updating login state
        }
    }
    else
    {
        statusMessage = "Login failed. Incorrect username or password."; // Username or password incorrect
    }
}
