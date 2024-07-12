// LoginCommand.cpp
#include "LoginHandler.h"


LoginHandler::LoginHandler(BankDataBase &db) : dataBase(db) {}

void LoginHandler::execute(const QStringList &RequestParts, QString &statusMessage)
{
    // Ensure RequestParts has at least 3 elements
    if (RequestParts.size() < 3)
    {
        statusMessage = "Invalid request. Please provide username and password.";
        return;
    }

    const QString userName = RequestParts[1];
    const QString passWord = RequestParts[2];
    bool isUserValid = false;
    QString userAuthority;
    QString userAccountNumber;
    QVector<QJsonObject> databaseRecords = dataBase.getMainDatabase(); // Get the main database records

    // Loop through each record in the database
    for (const auto& record : databaseRecords)
    {
        if (record["Username"].toString() == userName && record["Password"].toString() == passWord)
        {
            if (record["Login"].toString() == "0")
            {
                isUserValid = true;
                userAuthority = record["Authority"].toString(); // Capture user authority
                userAccountNumber = record["AccountNumber"].toString();
                break;
            }
            else
            {
                statusMessage="Login failed. This account is already logged in.";
                return;
            }
        }
    }

    if (isUserValid)
    {
        // Change the 'log' state in the database
        if (dataBase.setUserLoginState(userName, "1"))
        {
            QString successMessage = QString("%1:%2:%3").arg(userAuthority,userName,userAccountNumber);
            statusMessage = successMessage;
        }
        else
        {
            statusMessage="Login failed. Could not update the login state.";
        }
    }
    else
    {
        statusMessage = "Login failed. Incorrect username or password.";
    }
}
