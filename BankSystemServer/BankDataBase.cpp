#include "BankDataBase.h"

BankDataBase::BankDataBase(QObject *parent)
    : QObject{parent},
    mainDatabaseFilePath{"D:\\ITIDA_WorkSpace\\Qt_Sessions\\Final Project\\BankSystemServer\\mainDataBase.json"},
    transactionFilePath{"D:\\ITIDA_WorkSpace\\Qt_Sessions\\Final Project\\BankSystemServer\\transactionDataBase.json"}
{}

void BankDataBase::initializeMainDatabase()
{
    QFile file(mainDatabaseFilePath); // Open QFile for main database
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) // Check if file opened successfully
    {
        logger.logMessage("Error: Cannot open main database file");
        return;
    }

    QByteArray fileData = file.readAll(); // Read file content into QByteArray
    file.close();

    QJsonParseError parseError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(fileData, &parseError); // Convert QByteArray to QJsonDocument

    if (parseError.error != QJsonParseError::NoError)
    {
        logger.logMessage("Error: Failed to parse JSON from main database file");
        return;
    }

    if (!jsonDoc.isArray())
    {
        logger.logMessage("Error: Main database file does not contain a JSON array");
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
            logger.logMessage("Warning: Found non-object element in main database JSON array");
        }
    }
    logger.logMessage("Main database initialized with " + QString::number(mainDatabaseRecords.size()) + " records");
}




void BankDataBase::initializeTransactionDatabase()
{
    QFile file(transactionFilePath); // Open QFile for transaction database
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) // Check if file opened successfully
    {
        logger.logMessage("Error: Cannot open transaction database file");
        return;
    }

    QByteArray fileData = file.readAll(); // Read file content into QByteArray
    file.close();

    QJsonParseError parseError;
    QJsonDocument jsonDoc = QJsonDocument::fromJson(fileData, &parseError); // Convert QByteArray to QJsonDocument

    if (parseError.error != QJsonParseError::NoError)
    {
        logger.logMessage("Error: Failed to parse JSON from transaction database file");
        return;
    }

    if (!jsonDoc.isArray())
    {
        logger.logMessage("Error: Transaction database file does not contain a JSON array");
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
            logger.logMessage("Warning: Found non-object element in transaction database JSON array");
        }
    }
    logger.logMessage("Transaction database initialized with " + QString::number(transactionDatabaseRecords.size()) + " records");
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

bool BankDataBase::addClient(const QString &username, const QString &password, const QString &fullName,
                             const QString &age, const QString &email, const QString &balance )
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
    newClient["Login"] = "0";

    // Append the new client to the main database records
    mainDatabaseRecords.push_back(newClient);
    if (!saveMainDatabaseToFile())
    {
        logger.logMessage("Failed to save main database after adding new client.");
        return false;
    }

    QJsonObject newClientTrans;
    newClientTrans["AccountNumber"] = AccountNumber;
    newClientTrans["Transactions"] = QJsonArray();
    transactionDatabaseRecords.push_back(newClientTrans);

    // Save the updated transaction database to file
    if (!saveTransactionDatabaseToFile())
    {
        logger.logMessage("Failed to save transaction database after adding new client.");
        return false;
    }
    logger.logMessage("Client added successfully.");
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
        logger.logMessage("Main database file saved successfully.");
        return true; // Return true indicating success
    }
    else
    {
        logger.logMessage("Failed to save main database file.");
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
        logger.logMessage("Transaction database file saved successfully.");
        return true;
    }
    else
    {
        logger.logMessage("Failed to save transaction database file.");
        return false;
    }
}

bool BankDataBase::setUserLoginState(const QString& username, const QString& state)
{
    // Find the user in the main database records
    for (auto& record : mainDatabaseRecords)
    {
        if (record["Username"].toString() == username)
        {
            record["Login"] = state; // Update the login state

            // Save the updated main database records
            if (!saveMainDatabaseToFile())
            {
                logger.logMessage("Failed to save main database after updating login state for user: " + username);
                return false;
            }

            logger.logMessage("Login state updated successfully for user: " + username);
            return true;
        }
    }
    // Log and return false if the user was not found
    logger.logMessage("User not found for updating login state: " + username);
    return false;
}



bool BankDataBase::deleteClient(const QString &accountNumber)
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
            logger.logMessage("Deleting client from main database with AccountNumber: " + accountNumber);
            mainDatabaseRecords.remove(i);
            mainDatabaseDeleted = true;
            break;
        }
    }
    if(mainDatabaseDeleted == false)
    {
        logger.logMessage("This account number not found in main database");
        return false;
    }
    else
    {
        // Save the updated main database to file
        if (!saveMainDatabaseToFile())
        {
            logger.logMessage("Failed to save main database after deleting client.");
            return false;
        }
    }


    // Step 2: Remove from Transaction Database
    for (int i = 0; i < transactionDatabaseRecords.size(); ++i)
    {
        if (transactionDatabaseRecords[i]["AccountNumber"].toString() == accountNumber)
        {
            logger.logMessage("Deleting client from transaction database with AccountNumber: " + accountNumber);
            transactionDatabaseRecords.remove(i);
            transactionDatabaseDeleted = true;
            break;
        }
    }
    if(transactionDatabaseDeleted == false)
    {
        logger.logMessage("This account number not found in transaction database");
        return false;
    }
    else
    {
        // Save the updated main database to file
        if (!saveTransactionDatabaseToFile())
        {
            logger.logMessage("Failed to save transaction database after deleting client.");
            return false;
        }
    }

    // Return true if both deletions were successful
    return mainDatabaseDeleted && transactionDatabaseDeleted;
}



bool BankDataBase::updateClient(const QString &accountNumber, const QString &username, const QString &password
                                , const QString &fullName,const QString &ageStr, const QString &email)
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
            if (!username.isEmpty())
            {
                logger.logMessage("Updating username for account number: " + accountNumber);
                record["Username"] = username;
            }
            if (!password.isEmpty())
            {
                logger.logMessage("Updating password for account number: " + accountNumber);
                record["Password"] = password;
            }
            if (!fullName.isEmpty())
            {
                logger.logMessage("Updating full name for account number: " + accountNumber);
                record["FullName"] = fullName;
            }
            bool ok;
            int age = ageStr.toInt(&ok);
            if (ok && age != 0)
            {
                logger.logMessage("Updating age for account number: " + accountNumber);
                record["Age"] = ageStr;
            }
            if (!email.isEmpty())
            {
                logger.logMessage("Updating email for account number: " + accountNumber);
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
            logger.logMessage("Account information updated successfully for account number: " + accountNumber);
            return true; // Update successful
        }
        else
        {
            logger.logMessage("Failed to save updated account information for account number: " + accountNumber);
            return false; // Failed to save updated information
        }
    }
    else
    {
        logger.logMessage("Account not found. Update failed for account number: " + accountNumber);
        return false; // Account not found
    }
}



// Update transaction data
bool BankDataBase::transferMoney(const QString &sourceAccountNumber, const QString &targetAccountNumber,
                                 const QString &amountStr)
{
    // Validate the amounts
    bool AmountValid;
    int Amount = amountStr.toInt(&AmountValid);

    if (!AmountValid || Amount <= 0)
    {
        logger.logMessage("Invalid transfer amount from the source account.");
        return false;
    }

    // Check if source and target account numbers are different
    if (sourceAccountNumber == targetAccountNumber)
    {
        logger.logMessage("Source and target account numbers must be different.");
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
            if (currentSourceBalance < Amount)
            {
                logger.logMessage("Insufficient balance in the source account.");
                return false;
            }
            int newSourceBalance = currentSourceBalance - Amount;
            record["Balance"] = QString::number(newSourceBalance);
            sourceAccountFound = true;
        }

        if (record["AccountNumber"].toString() == targetAccountNumber)
        {
            QString currentTargetBalanceStr = record["Balance"].toString();
            int currentTargetBalance = currentTargetBalanceStr.toInt();
            int newTargetBalance = currentTargetBalance + Amount;
            record["Balance"] = QString::number(newTargetBalance);
            targetAccountFound = true;
        }
    }

    if (!sourceAccountFound)
    {
        logger.logMessage("Source account not found.");
        return false;
    }

    if (!targetAccountFound)
    {
        logger.logMessage("Target account not found.");
        return false;
    }

    // Save the updated main database records
    if (!saveMainDatabaseToFile())
    {
        logger.logMessage("Failed to save main database after transfer.");
        return false;
    }

    // Update the transaction record for the source account
    QJsonObject sourceTransaction;
    sourceTransaction["amount"] = "-" + QString::number(Amount);
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
    targetTransaction["amount"] = "+" + QString::number(Amount);
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

    if (!saveTransactionDatabaseToFile())
    {
        logger.logMessage("Failed to save transaction database after transfer.");
        return false;
    }

    logger.logMessage("Transfer successful.");
    return true;
}



bool BankDataBase::withdrawMoney(const QString &accountNumber, const QString &amount)
{
    // Validate the amount
    bool isNumber;
    int withdrawAmount = amount.toInt(&isNumber);
    if (!isNumber || withdrawAmount <= 0)
    {
        logger.logMessage("Invalid withdraw amount.");
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
                logger.logMessage("Insufficient balance.");
                return false;
            }
            int newBalance = currentBalance - withdrawAmount;
            record["Balance"] = QString::number(newBalance);
            accountFound = true;
            logger.logMessage("Withdrawal amount of " + QString::number(withdrawAmount) + " for account number: " + accountNumber);
            break;
        }
    }

    if (!accountFound)
    {
        logger.logMessage("Account not found for withdrawal: " + accountNumber);
        return false;
    }

    // Save the updated main database records
    if (!saveMainDatabaseToFile())
    {
        logger.logMessage("Failed to save main database after withdrawal for account number: " + accountNumber);
        return false;
    }

    // Update the transaction record
    QJsonObject transaction;
    transaction["amount"] = "-" + QString::number(withdrawAmount);
    transaction["date"] = QDate::currentDate().toString("dd.MM.yyyy");
    transaction["time"] = QDateTime::currentDateTime().toString("HH:mm:ss");

    for (auto& record : transactionDatabaseRecords)
    {
        if (record["AccountNumber"].toString() == accountNumber)
        {
            QJsonArray transactionsArray = record["Transactions"].toArray();
            transactionsArray.append(transaction);
            record["Transactions"] = transactionsArray;
            logger.logMessage("Updated transaction record for withdrawal for account number: " + accountNumber);
            break;
        }
    }

    // Save the updated transaction database records
    if (!saveTransactionDatabaseToFile())
    {
        logger.logMessage("Failed to save transaction database after withdrawal for account number: " + accountNumber);
        return false;
    }

    logger.logMessage("Withdrawal successful for account number: " + accountNumber);
    return true;
}


bool BankDataBase::depositMoney(const QString &accountNumber, const QString &amount)
{
    // Validate the amount
    bool isNumber;
    int depositAmount = amount.toInt(&isNumber);
    if (!isNumber || depositAmount <= 0)
    {
        logger.logMessage("Invalid deposit amount for account number: " + accountNumber);
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
            logger.logMessage("Deposited amount of " + QString::number(depositAmount) + " for account number: " + accountNumber);
            break;
        }
    }

    if (!accountFound)
    {
        logger.logMessage("Account not found for deposit: " + accountNumber);
        return false;
    }

    // Save the updated main database records
    if (!saveMainDatabaseToFile())
    {
        logger.logMessage("Failed to save main database after deposit for account number: " + accountNumber);
        return false;
    }

    // Update the transaction record
    QJsonObject transaction;
    transaction["amount"] = "+" + QString::number(depositAmount);
    transaction["date"] = QDate::currentDate().toString("dd.MM.yyyy");
    transaction["time"] = QDateTime::currentDateTime().toString("HH:mm:ss");

    for (auto& record : transactionDatabaseRecords)
    {
        if (record["AccountNumber"].toString() == accountNumber)
        {
            QJsonArray transactionsArray = record["Transactions"].toArray();
            transactionsArray.append(transaction);
            record["Transactions"] = transactionsArray;
            logger.logMessage("Updated transaction record for deposit for account number: " + accountNumber);
            break;
        }
    }

    // Save the updated transaction database records
    if (!saveTransactionDatabaseToFile())
    {
        logger.logMessage("Failed to save transaction database after deposit for account number: " + accountNumber);
        return false;
    }

    logger.logMessage("Deposit successful for account number: " + accountNumber);
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

    // Log the generated account number
    logger.logMessage(QString("Generated account number: %1").arg(accountNumber));

    return accountNumber;
}


QString BankDataBase::getEmailByAccountNumber(const QString &accountNumber)
{
    for (const auto &record : mainDatabaseRecords)
    {
        if (record["AccountNumber"].toString() == accountNumber)
        {
            QString email = record["Email"].toString();
            logger.logMessage(QString("Email found for account %1: %2").arg(accountNumber, email));
            return email;
        }
    }
    logger.logMessage(QString("Email not found for account: %1").arg(accountNumber));
    return "";
}





