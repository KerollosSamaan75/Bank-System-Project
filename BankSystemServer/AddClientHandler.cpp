#include "AddClientHandler.h"

AddClientHandler::AddClientHandler(BankDataBase &db) : dataBase(db) {}

void AddClientHandler::execute(const QStringList &RequestParts, QString &statusMessage)
{
    // Ensure RequestParts has at least 7 elements
    if (RequestParts.size() < 7)
    {
        statusMessage = "Invalid request. Please provide all required fields: full name, username, password, age, email, and balance.";
        return;
    }

    const QString fullName = RequestParts[1];
    const QString userName = RequestParts[2];
    const QString password = RequestParts[3];
    const QString ageStr = RequestParts[4];
    const QString email = RequestParts[5];
    const QString balanceStr = RequestParts[6];

    // Check if username already exists in the database
    QVector<QJsonObject> databaseRecords = dataBase.getMainDatabase(); // Get the main database records
    for (const auto& record : databaseRecords)
    {
        if (record["Username"].toString() == userName)
        {
            statusMessage = "This username is already taken. Please choose a different username.";
            return;
        }
    }

    // Add new user to the database
    if (dataBase.addClient(userName, password, fullName, ageStr, email, balanceStr))
    {
        statusMessage = QString("Congratulations! New user '%1' has been added. Welcome aboard").arg(userName);
    }
    else
    {
        statusMessage = QString("Sadly, new user '%1' couldn't be added to the database. Please try again.").arg(userName);
    }
}

