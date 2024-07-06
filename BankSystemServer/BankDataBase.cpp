#include "BankDataBase.h"

BankDataBase::BankDataBase(QObject *parent)
    : QObject{parent},inputStream{stdin},outputStream{stdout},
    mainDatabaseFilePath{"D:\\ITIDA_WorkSpace\\Qt_Sessions\\Final Project\\BankSystemServer\\mainDataBase.json"},
    transactionFilePath{"D:\\ITIDA_WorkSpace\\Qt_Sessions\\Final Project\\BankSystemServer\\transactionDataBase.json"}
{}

void BankDataBase::initializeMainDatabase()
{
    QFile file(mainDatabaseFilePath); // Open QFile for main database
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) // Check if file opened successfully
    {
        qDebug() << "Error: Cannot open main database file" <<Qt::endl;
        return;
    }

    QByteArray fileData = file.readAll(); // Read file content into QByteArray
    file.close();

    QJsonParseError parseError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(fileData, &parseError); // Convert QByteArray to QJsonDocument

    if (parseError.error != QJsonParseError::NoError)
    {
        qDebug() << "Error: Failed to parse JSON from main database file" <<Qt::endl;
        return;
    }

    if (!jsonDoc.isArray())
    {
        qDebug() << "Error: Main database file does not contain a JSON array"<<Qt::endl;
        return;
    }

    mainDatabaseRecords.clear(); // Clear existing data in vector

    QJsonArray jsonArray = jsonDoc.array(); // Convert QJsonDocument to QJsonArray for iteration

    // Iterate through JSON array and populate mainDatabaseRecords vector
    for (const auto& jsonValue : jsonArray)
    {
        if (jsonValue.isObject())
        {
            QJsonObject jsonObj = jsonValue.toObject(); // Extract object from array
            mainDatabaseRecords.push_back(jsonObj); // Append object to mainDatabaseRecords vector
        }
        else
        {
            qDebug() << "Warning: Found non-object element in main database JSON array";
        }
    }

    qDebug() << "Main database initialized with" << mainDatabaseRecords.size() << "records";
}



void BankDataBase::initializeTransactionDatabase()
{
    QFile file(transactionFilePath); // Open QFile for transaction database
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) // Check if file opened successfully
    {
        qDebug() << "Error: Cannot open transaction database file" <<Qt::endl;
        return;
    }

    QByteArray fileData = file.readAll(); // Read file content into QByteArray
    file.close();

    QJsonParseError parseError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(fileData, &parseError); // Convert QByteArray to QJsonDocument

    if (parseError.error != QJsonParseError::NoError)
    {
        qDebug() << "Error: Failed to parse JSON from transaction database file" <<Qt::endl;
        return;
    }

    if (!jsonDoc.isArray())
    {
        qDebug() << "Error: Transaction database file does not contain a JSON array";
        return;
    }

    transactionDatabaseRecords.clear(); // Clear existing data in vector

    QJsonArray jsonArray = jsonDoc.array(); // Convert QJsonDocument to QJsonArray for iteration

    // Iterate through JSON array and populate transactionRecords vector
    for (const auto& jsonValue : jsonArray)
    {
        if (jsonValue.isObject())
        {
            QJsonObject jsonObj = jsonValue.toObject(); // Extract object from array
            transactionDatabaseRecords.push_back(jsonObj); // Append object to transactionRecords vector
        }
        else
        {
            qDebug() << "Warning: Found non-object element in transaction database JSON array";
        }
    }

    qDebug() << "Transaction database initialized with" << transactionDatabaseRecords.size() << "records";
}


// Getter for retrieving data from the main database file
QVector<QJsonObject> BankDataBase::getMainDatabase()
{
    initializeMainDatabase(); // Ensure data is up-to-date
    return mainDatabaseRecords;
}

// Getter for retrieving data from the transaction database file
QVector<QJsonObject> BankDataBase::getTransactionDatabase()
{
    initializeTransactionDatabase(); // Ensure data is up-to-date
    return transactionDatabaseRecords;
}

bool BankDataBase::addClient(const QString username, const QString password,const QString fullName,
                              const QString age , const QString email, const QString balance)
{
    initializeMainDatabase();
    // Check if the user already exists
    for (const auto& record : mainDatabaseRecords)
    {
        if (record["Username"].toString() == username)
        {
            qDebug() << "User already exists!";
            return false;
        }
    }
    QString AccountNumber=generateAccountNumber();// Generate a unique account number
    // Create a new client object
    QJsonObject newClient;
    newClient["Username"] = username;
    newClient["Password"] = password;
    newClient["FullName"] = fullName;
    newClient["Age"] = age;
    newClient["Email"] = email;
    newClient["Authority"] = "Client"; // Assuming new clients are added as regular users
    newClient["Login"] = "0"; // Assuming initial login status is 0 (logged out)
    newClient["AccountNumber"] = AccountNumber;
    newClient["Balance"] = balance; // Initial balance is set to 0

    // Append the new client to the main database records
    mainDatabaseRecords.push_back(newClient);
    if(!saveMainDatabaseToFile())
    {
        qDebug() << "Failed to save main database after adding new client.";
        return false;
    }

    QJsonObject newClientTrans;
    newClientTrans["AccountNumber"] = AccountNumber;
    newClientTrans["Transactions"] = QJsonArray();
    transactionDatabaseRecords.push_back(newClientTrans);

    // Save the updated transaction database to file
    if (!saveTransactionDatabaseToFile())
    {
        qDebug() << "Failed to save transaction database after adding new client.";
        return false;
    }

    return true; // Return true indicating client addition succeeded
}

bool BankDataBase::saveMainDatabaseToFile()
{
    QJsonArray jsonArray; // Create a JSON array to hold database records

    // Convert each QJsonObject in mainDatabaseRecords to QJsonArray
    for (const auto& record : mainDatabaseRecords)
    {
        jsonArray.append(record);
    }

    // Convert QJsonArray to QJsonDocument
    QJsonDocument jsonDoc(jsonArray);

    // Convert QJsonDocument to QByteArray
    QByteArray jsonData = jsonDoc.toJson();

    // Write QByteArray to file
    QFile file(mainDatabaseFilePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text))
    {
        QTextStream out(&file);
        out << jsonData;
        file.close();
        qDebug() << "Main database file saved successfully.";
        return true; // Return true indicating success
    }
    else
    {
        qDebug() << "Failed to save main database file.";
        return false; // Return false indicating failure
    }
}

bool BankDataBase::saveTransactionDatabaseToFile()
{
    // Create a JSON array to hold transaction records
    QJsonArray jsonArray;

    // Convert each QJsonObject in transactionDatabaseRecords to QJsonArray
    for (const auto& record : transactionDatabaseRecords)
    {
        jsonArray.append(record);
    }

    // Convert QJsonArray to QJsonDocument
    QJsonDocument jsonDoc(jsonArray);

    // Convert QJsonDocument to QByteArray
    QByteArray jsonData = jsonDoc.toJson();

    // Write QByteArray to file
    QFile file(transactionFilePath);
    if (file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text))
    {
        QTextStream out(&file);
        out << jsonData;
        file.close();
        qDebug() << "Transaction database file saved successfully.";
        return true;
    }
    else
    {
        qDebug() << "Failed to save transaction database file.";
        return false;
    }
}



bool BankDataBase::deleteClient(const QString accountNumber)
{
    // Initialize the main database
    initializeMainDatabase();

    bool mainDatabaseDeleted = false;
    bool transactionDatabaseDeleted = false;

    // Step 1: Remove from Main Database
    for (int i = 0; i < mainDatabaseRecords.size(); ++i)
    {
        if (mainDatabaseRecords[i]["AccountNumber"].toString() == accountNumber)
        {
            mainDatabaseRecords.remove(i);
            mainDatabaseDeleted = true;
            break;
        }
    }

    // Save the updated main database to file
    if (!saveMainDatabaseToFile())
    {
        qDebug() << "Failed to save main database after deleting client.";
        return false;
    }

    // Step 2: Remove from Transaction Database
    for (int i = 0; i < transactionDatabaseRecords.size(); ++i)
    {
        if (transactionDatabaseRecords[i]["AccountNumber"].toString() == accountNumber)
        {
            transactionDatabaseRecords.remove(i);
            transactionDatabaseDeleted = true;
            break;
        }
    }

    // Save the updated transaction database to file
    if (!saveTransactionDatabaseToFile())
    {
        qDebug() << "Failed to save transaction database after deleting client.";
        return false;
    }

    // Return true if both deletions were successful
    return mainDatabaseDeleted && transactionDatabaseDeleted;
}


bool BankDataBase::updateClient(const QString accountNumber, const QString username, const QString password, const QString fullName, const QString ageStr, const QString email)
{
    // Load the main database records
    initializeMainDatabase();
    bool userFound = false;

    // Loop through each record in the database to find the matching user
    for (auto& record : mainDatabaseRecords)
    {
        if (record["AccountNumber"].toString() == accountNumber)
        {
            userFound = true;

            // Update only non-empty fields
            if (!username.isEmpty()) {
                record["Username"] = username;
            }
            if (!password.isEmpty()) {
                record["Password"] = password;
            }
            if (!fullName.isEmpty()) {
                record["FullName"] = fullName;
            }
            bool ok;
            int age = ageStr.toInt(&ok);
            if (ok && age != 0) {
                record["Age"] = ageStr;
            }
            if (!email.isEmpty()) {
                record["Email"] = email;
            }
            break;
        }
    }

    // Check if the user was found and updated
    if (userFound)
    {
        // Save the updated database to file
        if (saveMainDatabaseToFile())
        {
            return true; // Update successful
        }
        else
        {
            qDebug() << "Failed to save updated account information.";
            return false; // Failed to save updated information
        }
    }
    else
    {
        qDebug() << "Account not found. Update failed.";
        return false; // Account not found
    }
}

bool BankDataBase::setUserLoginState(const QString& username, const QString& state)
{
    QFile file(mainDatabaseFilePath); // QFile instance to interact with the database file

    // Attempt to open the file in ReadWrite mode
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text))
    {
        qDebug() << "Unable to open the main database file for reading and writing.";
        return false;
    }

    QByteArray fileData = file.readAll(); // Read the file data into a QByteArray
    file.close(); // Close the file after reading the content

    QJsonDocument jsonDoc = QJsonDocument::fromJson(fileData); // Convert QByteArray to QJsonDocument

    // Check if the JSON document is valid and is an array
    if (jsonDoc.isNull() || !jsonDoc.isArray())
    {
        qDebug() << "Invalid JSON format in the database file.";
        return false;
    }

    QJsonArray jsonArray = jsonDoc.array(); // Convert QJsonDocument to QJsonArray
    bool userFound = false;

    // Use iterators for traversing and updating the JSON array
    for (QJsonArray::iterator it = jsonArray.begin(); it != jsonArray.end(); ++it)
    {
        QJsonObject userObject = it->toObject();
        if (userObject["Username"].toString() == username)
        {
            userObject["Login"] = state; // Update the login state
            *it = userObject; // Update the array with the modified object
            userFound = true;
            break;
        }
    }

    if (!userFound)
    {
        qDebug() << "User not found in the database.";
        return false;
    }

    // Convert the updated JSON array back to QJsonDocument
    QJsonDocument updatedJsonDoc(jsonArray);
    QByteArray updatedFileData = updatedJsonDoc.toJson();

    // Reopen the file in write mode and write the updated content
    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text))
    {
        qDebug() << "Unable to open the database file for writing.";
        return false;
    }

    file.write(updatedFileData);
    file.close();

    qDebug() << "User login state updated successfully for user:" << username;
    return true;
}



bool BankDataBase::transferMoney(const QString accountNumberFrom, const QString accountNumberTo, const QString amountInFrom, const QString amountInTo, const QString amount)
{

}

bool BankDataBase::withdrawMoney(const QString accountNumber, const QString amount)
{

}



bool BankDataBase::depositMoney(const QString accountNumber, const QString amount)
{
    // Validate the amount
    bool isNumber;
    int depositAmount = amount.toInt(&isNumber);
    if (!isNumber || depositAmount <= 0)
    {
        qDebug() << "Invalid deposit amount.";
        return false;
    }


    // Find the account and update the balance
    bool accountFound = false;
    for (auto& record : mainDatabaseRecords)
    {
        if (record["AccountNumber"].toString() == accountNumber)
        {
            QString str = record["Balance"].toString();
            int currentBalance = str.toInt();
            int newBalance = currentBalance + depositAmount;
            record["Balance"] = QString::number(newBalance);
            accountFound = true;
            break;
        }
    }

    if (!accountFound)
    {
        qDebug() << "Account not found.";
        return false;
    }

    // Save the updated main database records
    if (!saveMainDatabaseToFile())
    {
        qDebug() << "Failed to save main database after deposit.";
        return false;
    }

    // Update the transaction record
    QJsonObject transaction;
    transaction["amount"] = "+" + QString::number(depositAmount);
    transaction["date"] = QDate::currentDate().toString("dd.MM.yyyy");

    for (auto& record : transactionDatabaseRecords)
    {
        if (record["AccountNumber"].toString() == accountNumber)
        {
            QJsonArray transactionsArray = record["Transactions"].toArray();
            transactionsArray.append(transaction);
            record["Transactions"] = transactionsArray;
            break;
        }
    }

    if (!saveTransactionDatabaseToFile())
    {
        qDebug() << "Failed to save transaction database after deposit.";
        return false;
    }

    return true;
}




QString BankDataBase::generateAccountNumber()
{
    // Get the current timestamp
    qint64 timestamp = QDateTime::currentSecsSinceEpoch();

    // Generate a random number between 1000 and 9999
    int randomNum = QRandomGenerator::global()->bounded(1000, 10000);

    // Combine the timestamp and the random number to create the account number
    QString accountNumber = QString::number(timestamp).right(5) + QString::number(randomNum);

    return accountNumber;
}


