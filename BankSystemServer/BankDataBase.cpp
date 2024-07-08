#include "BankDataBase.h"

BankDataBase::BankDataBase(QObject *parent)
    : QObject{parent},
    mainDatabaseFilePath{"D:\\ITIDA_WorkSpace\\Qt_Sessions\\Final Project\\BankSystemServer\\mainDataBase.json"},
    transactionFilePath{"D:\\ITIDA_WorkSpace\\Qt_Sessions\\Final Project\\BankSystemServer\\transactionDataBase.json"}
{}

void BankDataBase::initializeMainDatabase(QString &statusMessage)
{
    QFile file(mainDatabaseFilePath); // Open QFile for main database
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) // Check if file opened successfully
    {
        statusMessage = "Error: Cannot open main database file\n";
        return;
    }

    QByteArray fileData = file.readAll(); // Read file content into QByteArray
    file.close();

    QJsonParseError parseError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(fileData, &parseError); // Convert QByteArray to QJsonDocument

    if (parseError.error != QJsonParseError::NoError)
    {
        statusMessage = "Error: Failed to parse JSON from main database file\n";
        return;
    }

    if (!jsonDoc.isArray())
    {
        statusMessage = "Error: Main database file does not contain a JSON array\n";
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
            statusMessage = "Warning: Found non-object element in main database JSON array\n";
        }
    }
    statusMessage = "Main database initialized with " + QString::number(mainDatabaseRecords.size()) + " records\n";
}




void BankDataBase::initializeTransactionDatabase(QString &statusMessage)
{
    QFile file(transactionFilePath); // Open QFile for transaction database
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) // Check if file opened successfully
    {
        statusMessage =  "Error: Cannot open transaction database file\n";
        return;
    }

    QByteArray fileData = file.readAll(); // Read file content into QByteArray
    file.close();

    QJsonParseError parseError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(fileData, &parseError); // Convert QByteArray to QJsonDocument

    if (parseError.error != QJsonParseError::NoError)
    {
        statusMessage =  "Error: Failed to parse JSON from transaction database file\n";
        return;
    }

    if (!jsonDoc.isArray())
    {
        statusMessage = "Error: Transaction database file does not contain a JSON array\n";
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
            statusMessage = "Warning: Found non-object element in transaction database JSON array\n";
        }
    }
    statusMessage = "Transaction database initialized with " + QString::number(transactionDatabaseRecords.size()) + " records\n";
}


// Getter for retrieving data from the main database file
QVector<QJsonObject> BankDataBase::getMainDatabase(QString &statusMessage)
{
    initializeMainDatabase(statusMessage); // Ensure data is up-to-date
    return mainDatabaseRecords;
}

// Getter for retrieving data from the transaction database file
QVector<QJsonObject> BankDataBase::getTransactionDatabase(QString &statusMessage)
{
    initializeTransactionDatabase(statusMessage); // Ensure data is up-to-date
    return transactionDatabaseRecords;
}

bool BankDataBase::addClient(const QString username, const QString password, const QString fullName,
                             const QString age, const QString email, const QString balance ,QString &statusMessage)
{
    QString AccountNumber = generateAccountNumber(); // Generate a unique account number

    // Create a new client object
    QJsonObject newClient;
    newClient["Username"] = username;
    newClient["Password"] = password;
    newClient["FullName"] = fullName;
    newClient["Age"] = age;
    newClient["Email"] = email;
    newClient["Authority"] = "Client"; // Assuming new clients are added as regular users
    newClient["AccountNumber"] = AccountNumber;
    newClient["Balance"] = balance; // Initial balance is set to 0

    // Append the new client to the main database records
    mainDatabaseRecords.push_back(newClient);
    if (!saveMainDatabaseToFile(statusMessage))
    {
        statusMessage += "Failed to save main database after adding new client.\n";
        return false;
    }

    QJsonObject newClientTrans;
    newClientTrans["AccountNumber"] = AccountNumber;
    newClientTrans["Transactions"] = QJsonArray();
    transactionDatabaseRecords.push_back(newClientTrans);

    // Save the updated transaction database to file
    if (!saveTransactionDatabaseToFile(statusMessage))
    {
        statusMessage += "Failed to save transaction database after adding new client.\n";
        return false;
    }
    statusMessage += "Client added successfully.\n";
    return true; // Return true indicating client addition succeeded
}


bool BankDataBase::saveMainDatabaseToFile(QString &statusMessage)
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
        statusMessage += "Main database file saved successfully.\n";
        return true; // Return true indicating success
    }
    else
    {
        statusMessage += "Failed to save main database file.\n";
        return false; // Return false indicating failure
    }
}

bool BankDataBase::saveTransactionDatabaseToFile(QString &statusMessage)
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
        statusMessage += "Transaction database file saved successfully.\n";
        return true;
    }
    else
    {
        statusMessage +="Failed to save transaction database file.\n";
        return false;
    }
}




bool BankDataBase::deleteClient(const QString accountNumber ,QString &statusMessage)
{
    // Initialize the main database
    initializeMainDatabase(statusMessage);

    bool mainDatabaseDeleted = false;
    bool transactionDatabaseDeleted = false;

    // Step 1: Remove from Main Database
    for (int i = 0; i < mainDatabaseRecords.size(); ++i)
    {
        if (mainDatabaseRecords[i]["AccountNumber"].toString() == accountNumber)
        {
            statusMessage += "Deleting client from main database with AccountNumber: " + accountNumber+"\n";
            mainDatabaseRecords.remove(i);
            mainDatabaseDeleted = true;
            break;
        }
    }
    if(mainDatabaseDeleted == false)
    {
        statusMessage +="This account number not found in main database\n";
        return false;
    }
    else
    {
        // Save the updated main database to file
        if (!saveMainDatabaseToFile(statusMessage))
        {
            statusMessage += "Failed to save main database after deleting client.\n";
            return false;
        }
    }


    // Step 2: Remove from Transaction Database
    for (int i = 0; i < transactionDatabaseRecords.size(); ++i)
    {
        if (transactionDatabaseRecords[i]["AccountNumber"].toString() == accountNumber)
        {
            statusMessage += "Deleting client from transaction database with AccountNumber: " + accountNumber+"\n";
            transactionDatabaseRecords.remove(i);
            transactionDatabaseDeleted = true;
            break;
        }
    }
    if(transactionDatabaseDeleted == false)
    {
        statusMessage +="This account number not found in transaction database \n";
        return false;
    }
    else
    {
        // Save the updated main database to file
        if (!saveTransactionDatabaseToFile(statusMessage))
        {
            statusMessage += "Failed to save transaction database after deleting client.\n";
            return false;
        }
    }

    // Return true if both deletions were successful
    return mainDatabaseDeleted && transactionDatabaseDeleted;
}



bool BankDataBase::updateClient(const QString accountNumber, const QString username, const QString password
                                , const QString fullName,const QString ageStr, const QString email ,QString &statusMessage)
{
    // Load the main database records
    initializeMainDatabase(statusMessage);
    bool userFound = false;

    // Loop through each record in the database to find the matching user
    for (auto& record : mainDatabaseRecords)
    {
        if (record["AccountNumber"].toString() == accountNumber)
        {
            userFound = true;

            // Update only non-empty fields
            if (!username.isEmpty())
            {
                statusMessage += "Updating username for account number: " + accountNumber+"\n";
                record["Username"] = username;
            }
            if (!password.isEmpty())
            {
                statusMessage += "Updating password for account number: " + accountNumber+"\n";
                record["Password"] = password;
            }
            if (!fullName.isEmpty())
            {
                statusMessage += "Updating full name for account number: " + accountNumber+"\n";
                record["FullName"] = fullName;
            }
            bool ok;
            int age = ageStr.toInt(&ok);
            if (ok && age != 0)
            {
                statusMessage += "Updating age for account number: " + accountNumber+"\n";
                record["Age"] = ageStr;
            }
            if (!email.isEmpty())
            {
                statusMessage += "Updating email for account number: " + accountNumber+"\n";
                record["Email"] = email;
            }
            break;
        }
    }

    // Check if the user was found and updated
    if (userFound)
    {
        // Save the updated database to file
        if (saveMainDatabaseToFile(statusMessage))
        {
            statusMessage += "Account information updated successfully for account number: " + accountNumber+"\n";
            return true; // Update successful
        }
        else
        {
            statusMessage += "Failed to save updated account information for account number: " + accountNumber+"\n";
            return false; // Failed to save updated information
        }
    }
    else
    {
        statusMessage += "Account not found. Update failed for account number: " + accountNumber+"\n";
        return false; // Account not found
    }
}



// Update transaction data
bool BankDataBase::transferMoney(const QString sourceAccountNumber, const QString targetAccountNumber,
                                 const QString sourceAmountStr, const QString targetAmountStr, QString &statusMessage)
{
    // Validate the amounts
    bool isSourceAmountValid, isTargetAmountValid;
    int sourceAmount = sourceAmountStr.toInt(&isSourceAmountValid);
    int targetAmount = targetAmountStr.toInt(&isTargetAmountValid);

    if (!isSourceAmountValid || sourceAmount <= 0)
    {
        statusMessage += "Invalid transfer amount from the source account.\n";
        return false;
    }

    if (!isTargetAmountValid || targetAmount <= 0)
    {
        statusMessage += "Invalid transfer amount to the target account.\n";
        return false;
    }

    // Check if source and target account numbers are different
    if (sourceAccountNumber == targetAccountNumber)
    {
        statusMessage += "Source and target account numbers must be different.\n";
        return false;
    }

    // Find the source and target accounts and update the balances
    bool sourceAccountFound = false;
    bool targetAccountFound = false;
    for (auto& record : mainDatabaseRecords)
    {
        if (record["AccountNumber"].toString() == sourceAccountNumber)
        {
            QString  currentSourceBalanceStr = record["Balance"].toString();
            int currentSourceBalance = currentSourceBalanceStr.toInt();
            if (currentSourceBalance < sourceAmount)
            {
                statusMessage += "Insufficient balance in the source account.\n";
                return false;
            }
            int newSourceBalance = currentSourceBalance - sourceAmount;
            record["Balance"] = QString::number(newSourceBalance);
            sourceAccountFound = true;
        }

        if (record["AccountNumber"].toString() == targetAccountNumber)
        {
            QString currentTargetBalanceStr = record["Balance"].toString();
            int currentTargetBalance = currentTargetBalanceStr.toInt();
            int newTargetBalance = currentTargetBalance + targetAmount;
            record["Balance"] = QString::number(newTargetBalance);
            targetAccountFound = true;
        }
    }

    if (!sourceAccountFound)
    {
        statusMessage += "Source account not found.\n";
        return false;
    }

    if (!targetAccountFound)
    {
        statusMessage += "Target account not found.\n";
        return false;
    }

    // Save the updated main database records
    if (!saveMainDatabaseToFile(statusMessage))
    {
        statusMessage += "Failed to save main database after transfer.\n";
        return false;
    }

    // Update the transaction record for the source account
    QJsonObject sourceTransaction;
    sourceTransaction["amount"] = "-" + QString::number(sourceAmount);
    sourceTransaction["date"] = QDate::currentDate().toString("dd.MM.yyyy");

    for (auto& record : transactionDatabaseRecords)
    {
        if (record["AccountNumber"].toString() == sourceAccountNumber)
        {
            QJsonArray transactionsArray = record["Transactions"].toArray();
            transactionsArray.append(sourceTransaction);
            record["Transactions"] = transactionsArray;
            break;
        }
    }

    // Update the transaction record for the target account
    QJsonObject targetTransaction;
    targetTransaction["amount"] = "+" + QString::number(targetAmount);
    targetTransaction["date"] = QDate::currentDate().toString("dd.MM.yyyy");

    for (auto& record : transactionDatabaseRecords)
    {
        if (record["AccountNumber"].toString() == targetAccountNumber)
        {
            QJsonArray transactionsArray = record["Transactions"].toArray();
            transactionsArray.append(targetTransaction);
            record["Transactions"] = transactionsArray;
            break;
        }
    }

    if (!saveTransactionDatabaseToFile(statusMessage))
    {
        statusMessage += "Failed to save transaction database after transfer.\n";
        return false;
    }

    statusMessage += "Transfer successful.\n";
    return true;
}



bool BankDataBase::withdrawMoney(const QString accountNumber, const QString amount, QString& statusMessage)
{
    // Validate the amount
    bool isNumber;
    int withdrawAmount = amount.toInt(&isNumber);
    if (!isNumber || withdrawAmount <= 0)
    {
        statusMessage += "Invalid withdraw amount.\n";
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
            if (withdrawAmount > currentBalance)
            {
                statusMessage += "Insufficient balance.\n";
                return false;
            }
            int newBalance = currentBalance - withdrawAmount;
            record["Balance"] = QString::number(newBalance);
            accountFound = true;
            statusMessage += "Withdrawal amount of " + QString::number(withdrawAmount) + " for account number: " + accountNumber+"\n";
            break;
        }
    }

    if (!accountFound)
    {
        statusMessage += "Account not found for withdrawal: " + accountNumber+"\n";
        return false;
    }

    // Save the updated main database records
    if (!saveMainDatabaseToFile(statusMessage))
    {
        statusMessage += "Failed to save main database after withdrawal for account number: " + accountNumber+"\n";
        return false;
    }

    // Update the transaction record
    QJsonObject transaction;
    transaction["amount"] = "-" + QString::number(withdrawAmount);
    transaction["date"] = QDate::currentDate().toString("dd.MM.yyyy");

    for (auto& record : transactionDatabaseRecords)
    {
        if (record["AccountNumber"].toString() == accountNumber)
        {
            QJsonArray transactionsArray = record["Transactions"].toArray();
            transactionsArray.append(transaction);
            record["Transactions"] = transactionsArray;
            statusMessage += "Updated transaction record for withdrawal for account number: " + accountNumber+"\n";
            break;
        }
    }

    // Save the updated transaction database records
    if (!saveTransactionDatabaseToFile(statusMessage))
    {
        statusMessage += "Failed to save transaction database after withdrawal for account number: " + accountNumber+"\n";
        return false;
    }

    statusMessage += "Withdrawal successful for account number: " + accountNumber+"\n";
    return true;
}


bool BankDataBase::depositMoney(const QString accountNumber, const QString amount, QString& statusMessage)
{
    // Validate the amount
    bool isNumber;
    int depositAmount = amount.toInt(&isNumber);
    if (!isNumber || depositAmount <= 0)
    {
        statusMessage += "Invalid deposit amount for account number: " + accountNumber+"\n";
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
            statusMessage += "Deposited amount of " + QString::number(depositAmount) + " for account number: " + accountNumber+"\n";
            break;
        }
    }

    if (!accountFound)
    {
        statusMessage += "Account not found for deposit: " + accountNumber+"\n";
        return false;
    }

    // Save the updated main database records
    if (!saveMainDatabaseToFile(statusMessage))
    {
        statusMessage +="Failed to save main database after deposit for account number: " + accountNumber+"\n";
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
            statusMessage += "Updated transaction record for deposit for account number: " + accountNumber+"\n";
            break;
        }
    }

    // Save the updated transaction database records
    if (!saveTransactionDatabaseToFile(statusMessage))
    {
        statusMessage +="Failed to save transaction database after deposit for account number: " + accountNumber+"\n";
        return false;
    }

    statusMessage = "Deposit successful for account number: " + accountNumber+"\n";
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


