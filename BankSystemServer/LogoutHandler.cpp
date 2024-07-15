#include "LogoutHandler.h"

// Constructor for LogoutHandler, initializing with a reference to BankDataBase
LogoutHandler::LogoutHandler(BankDataBase &db) : dataBase(db) {}

// Execute function implementation, handling logout requests
void LogoutHandler::execute(const QStringList &RequestParts, QString &statusMessage)
{
    // Ensure RequestParts has at least 2 elements
    if (RequestParts.size() < 2)
    {
        statusMessage = "Invalid request. Please provide username.";
        return;
    }

    const QString userName = RequestParts[1]; // Extract username from RequestParts
    bool isUserLoggedIn = false; // Flag to track if user is currently logged in
    QVector<QJsonObject> databaseRecords = dataBase.getMainDatabase(); // Retrieve main database records

    // Loop through each record in the database
    for (const auto& record : databaseRecords)
    {
        // Check if username matches and user is currently logged in
        if (record["Username"].toString() == userName && record["Login"].toString() == "1")
        {
            isUserLoggedIn = true; // Mark user as currently logged in
            break; // Exit loop as user is found
        }
    }

    // Process based on whether user is logged in or not
    if (isUserLoggedIn)
    {
        // Change the 'log' state in the database
        if (dataBase.setUserLoginState(userName, "0"))
        {
            statusMessage = "Logout successful."; // Set status message to indicate successful logout
        }
        else
        {
            statusMessage = "Logout failed. Could not update the login state."; // Error updating login state
        }
    }
    else
    {
        statusMessage = "Logout failed. User is not currently logged in."; // User is not logged in
    }
}
