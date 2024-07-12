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
            isUserValid = true;
            userAuthority = record["Authority"].toString(); // Capture user authority
            userAccountNumber = record["AccountNumber"].toString();
            break;
        }
    }

    if (isUserValid)
    {
        // Change the 'log' state in the database
        statusMessage = QString("%1:%2:%3").arg(userAuthority, userName, userAccountNumber);
    }
    else
    {
        statusMessage = "Login failed. Incorrect username or password.";
    }
}
