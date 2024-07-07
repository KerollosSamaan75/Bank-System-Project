#include "ServerHandler.h"


ServerHandler::ServerHandler(qint32 ID, QObject *parent)
    : QThread(parent)
{
    this->ID = ID;
}

void ServerHandler::run()
{
    statusMessage = "User with ID: "+QString::number(ID)+" is running on thread";
    Logger::instance().logMessage(statusMessage);
    Socket = new QTcpSocket();
    Socket->setSocketDescriptor(ID);
    connect(Socket, &QTcpSocket::readyRead, this, &ServerHandler::onReadyRead, Qt::DirectConnection);
    connect(Socket, &QTcpSocket::disconnected, this, &ServerHandler::onDisconnected, Qt::DirectConnection);

    dataBase.initializeMainDatabase(statusMessage);
    Logger::instance().logMessage(statusMessage);

    dataBase.initializeTransactionDatabase(statusMessage);
    Logger::instance().logMessage(statusMessage);
    exec();
}

void ServerHandler::onReadyRead()
{
    QByteArray ByteArr = Socket->readAll();
    statusMessage= QString("My Server Received Data From User: %1 Data => %2").arg(ID).arg(QString(ByteArr));
    Logger::instance().logMessage(statusMessage);
    Operation(QString(ByteArr));
}

void ServerHandler::onDisconnected()
{
    if(Socket->isOpen())
    {
        Socket->close();
        statusMessage = "User with ID: "+QString::number(ID)+"has disconnected";
        Logger::instance().logMessage(statusMessage);
    }
}

void ServerHandler::Operation(QString Request)
{
    QStringList List = Request.split(":");
    if (List[0] == "Login")
    {
        loginToServer(List);
    }
    if (List[0] == "AddAccount")
    {
        addNewClient(List);
    }
    if (List[0] == "GetAccountNumber")
    {
        getClientAccountNumber(List);
    }
    if (List[0] == "DeleteAccount")
    {
        deleteClientAccount(List);
    }
    if (List[0] == "GetAccountBalance")
    {
        getClientAccountBalance(List);
    }
    if (List[0] == "ViewTransactions")
    {
        getClientTransactionHistory(List);
    }
    if (List[0] == "ViewBankDatabase")
    {
        getBankDataBase(List);
    }
    if (List[0] == "UpdateAccount")
    {
        updateClientAccount(List);
    }
    if (List[0] == "MakeTransaction")
    {
        makeTransaction(List);
    }
    if(List[0]=="TransferMoney")
    {
        makeTransfer(List);
    }
}

void ServerHandler::loginToServer(const QStringList& RequestParts)
{
    // Ensure RequestParts has at least 3 elements
    if (RequestParts.size() < 3)
    {
        statusMessage = "Invalid request. Please provide username and password.";
        sendMessage(statusMessage);
        return;
    }

    const QString tempName = RequestParts[1];
    const QString tempPass = RequestParts[2];
    bool isUserValid = false;
    QString userAuthority;
    QString userAccountNumber;
    QVector<QJsonObject> databaseRecords = dataBase.getMainDatabase(statusMessage); // Get the main database records
    Logger::instance().logMessage(statusMessage);

    // Loop through each record in the database
    for (const auto& record : databaseRecords)
    {
        if (record["Username"].toString() == tempName && record["Password"].toString() == tempPass)
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
        userName = tempName;
        password = tempPass;

        statusMessage = QString("%1:%2:%3").arg(userAuthority, userName, userAccountNumber);
        sendMessage(statusMessage);
    }
    else
    {
        statusMessage = "Login failed. Incorrect username or password.";
        sendMessage(statusMessage);
    }
}

void ServerHandler::addNewClient(const QStringList& RequestParts)
{
    // Ensure RequestParts has at least 7 elements
    if (RequestParts.size() < 7)
    {
        statusMessage = "Invalid request. Please provide all required fields: full name, username, password, age, email, and balance.";
        sendMessage(statusMessage);
        return;
    }

    const QString fullName = RequestParts[1];
    const QString userName = RequestParts[2];
    const QString password = RequestParts[3];
    const QString ageStr = RequestParts[4];
    const QString email = RequestParts[5];
    const QString balanceStr = RequestParts[6];

    // Check if username already exists in the database
    QVector<QJsonObject> databaseRecords = dataBase.getMainDatabase(statusMessage); // Get the main database records
    Logger::instance().logMessage(statusMessage);
    for (const auto& record : databaseRecords)
    {
        if (record["Username"].toString() == userName)
        {
            statusMessage = "This username is already taken. Please choose a different username.";
            sendMessage(statusMessage);
            return;
        }
    }

    // Add new user to the database
    if (dataBase.addClient(userName, password, fullName, ageStr, email, balanceStr ,statusMessage))
    {
        Logger::instance().logMessage(statusMessage);
        statusMessage = QString("Congratulations! New user '%1' has been added. Welcome aboard").arg(userName);
        sendMessage(statusMessage);
    }
    else
    {
        Logger::instance().logMessage(statusMessage);
        statusMessage = QString("Sadly, new user '%1' couldn't be added to the database. Please try again.").arg(userName);
        sendMessage(statusMessage);
    }
}

void ServerHandler::getClientAccountNumber(const QStringList& RequestParts)
{
    // Ensure RequestParts has the necessary elements
    if (RequestParts.size() < 2)
    {
        statusMessage = "Invalid request. Please provide username or identifier.";
        sendMessage(statusMessage);
        return;
    }

    QString username = RequestParts[1]; // Assuming username is in RequestParts[1]
    QVector<QJsonObject> databaseRecords = dataBase.getMainDatabase(statusMessage);
    Logger::instance().logMessage(statusMessage);

    // Search for the username in databaseRecords
    QString accountNumber;
    bool found = false;
    for (const auto& record : databaseRecords)
    {
        if (record["Username"].toString() == username)
        {
            accountNumber = record["AccountNumber"].toString(); // Adjust this based on your actual JSON structure
            found = true;
            break;
        }
    }

    // Check if the username was found
    if (found)
    {
        // Send the account number as a response
        statusMessage = QString("Account number for %1 is: %2").arg(username).arg(accountNumber);
        sendMessage(statusMessage);
    }
    else
    {
        // Send an error message if the username was not found
        statusMessage = QString("Account number for %1 not found.").arg(username);
        sendMessage(statusMessage);
    }
}

void ServerHandler::deleteClientAccount(const QStringList& RequestParts)
{
    // Ensure RequestParts has the necessary elements
    if (RequestParts.size() < 2)
    {
        statusMessage = "Invalid request. Please provide the account number.";
        sendMessage(statusMessage);
        return;
    }

    QString accountNumber = RequestParts[1]; // Assuming account number is in RequestParts[1]

    // Attempt to delete the client from the database
    bool success = dataBase.deleteClient(accountNumber,statusMessage);
    Logger::instance().logMessage(statusMessage);

    if (success)
    {
        statusMessage = QString("Client account with account number %1 has been successfully deleted.").arg(accountNumber);
        sendMessage(statusMessage);
    }
    else
    {   statusMessage = QString("Failed to delete client account with account number %1. The account may not exist.").arg(accountNumber);
        sendMessage(statusMessage);
    }
}

void ServerHandler::getClientAccountBalance(const QStringList& RequestParts)
{
    // Ensure RequestParts has the necessary elements
    if (RequestParts.size() < 2)
    {
        sendMessage("Invalid request. Please provide the username or account number.");
        return;
    }

    QString accountNumber = RequestParts[1]; // Assuming the identifier (account number) is in RequestParts[1]
    QVector<QJsonObject> databaseRecords = dataBase.getMainDatabase(statusMessage); // Get the main database records
    Logger::instance().logMessage(statusMessage);

    // Flag to check if client is found
    bool clientFound = false;
    QString balance;
    QString userName;

    // Loop through each record in the database
    for (const auto& record : databaseRecords)
    {
        if (record["AccountNumber"].toString() == accountNumber)
        {
            balance = record["Balance"].toString();
            userName = record["Username"].toString();
            clientFound = true;
            break;
        }
    }

    if (clientFound)
    {
        statusMessage = QString("The account balance for %1 is %2.").arg(userName, balance);
        sendMessage(statusMessage);
    }
    else
    {
        statusMessage = QString("Client with account number %1 not found.").arg(accountNumber);
        sendMessage(statusMessage);
    }
}

void ServerHandler::getClientTransactionHistory(const QStringList& RequestParts)
{
    // Ensure RequestParts has the necessary elements
    if (RequestParts.size() < 3)
    {
        statusMessage = "Invalid request. Please provide account number and history count.";
        sendMessage(statusMessage);
        return;
    }

    QString accountNumber = RequestParts[1]; // Assuming account number is in RequestParts[1]
    bool isNumber;
    int historyCount = RequestParts[2].toInt(&isNumber);

    // Validate the history count
    if (!isNumber || historyCount <= 0 || historyCount > 20)
    {
        statusMessage = "Invalid history count. Please provide a number between 1 and 20.";
        sendMessage(statusMessage);
        return;
    }

    // Get the transaction database records
    QVector<QJsonObject> transactionRecords = dataBase.getTransactionDatabase(statusMessage);
    Logger::instance().logMessage(statusMessage);

    // Find the account transactions
    QJsonObject accountTransactions;
    bool accountFound = false;
    for (const auto& record : transactionRecords)
    {
        if (record["AccountNumber"].toString() == accountNumber)
        {
            accountTransactions = record;
            accountFound = true;
            break;
        }
    }

    // Check if the account was found
    if (!accountFound)
    {
        statusMessage = "Account not found.";
        sendMessage(statusMessage);
        return;
    }

    // Get the transactions array
    QJsonArray transactionsArray = accountTransactions["Transactions"].toArray();

    // Prepare the response
    QJsonArray recentTransactions;
    int transactionsCount = transactionsArray.size();
    for (int i = transactionsCount - historyCount; i < transactionsCount; ++i)
    {
        if (i >= 0)
        {
            recentTransactions.append(transactionsArray[i]);
        }
    }

    QJsonObject response;
    response["AccountNumber"] = accountNumber;
    response["RecentTransactions"] = recentTransactions;

    QJsonDocument doc(response);
    statusMessage = "TransactionHistory:" + QString(doc.toJson(QJsonDocument::Compact));
    sendMessage(statusMessage);
}

void ServerHandler::getBankDataBase(const QStringList& RequestParts)
{
    // Ensure the request is valid
    if (RequestParts.isEmpty() || RequestParts[0] != "ViewBankDatabase")
    {
        statusMessage = "Invalid request. Expected 'ViewBankDatabase'.";
        sendMessage(statusMessage);
        return;
    }

    // Get the bank database records
    QVector<QJsonObject> bankRecords = dataBase.getMainDatabase(statusMessage);
    Logger::instance().logMessage(statusMessage);

    // Prepare the response
    QJsonArray bankRecordsArray;
    for (const auto& record : bankRecords)
    {
        bankRecordsArray.append(record);
    }

    QJsonDocument doc(bankRecordsArray);
    statusMessage = "ViewBankDataBase:" + QString(doc.toJson(QJsonDocument::Compact));
    sendMessage(statusMessage);
}

void ServerHandler::updateClientAccount(const QStringList& RequestParts)
{
    // Ensure RequestParts has the necessary elements
    if (RequestParts.size() < 7)
    {
        statusMessage = "Invalid request. Please provide all required fields.";
        sendMessage(statusMessage);
        return;
    }

    QString fullName = RequestParts[1];
    QString userName = RequestParts[2];
    QString passWord = RequestParts[3];
    QString age = RequestParts[4];
    QString email = RequestParts[5];
    QString accountNumber = RequestParts[6];

    // Update the client account in the database
    bool success = dataBase.updateClient(accountNumber, userName, passWord, fullName, age, email,statusMessage);
    Logger::instance().logMessage(statusMessage);
    // Send appropriate response based on update result
    if (success)
    {
        statusMessage = "Account update successful.";
        sendMessage(statusMessage);
    }
    else
    {
        statusMessage = "Account update failed. Please check the account number and try again.";
        sendMessage(statusMessage);
    }
}

void ServerHandler::makeTransaction(const QStringList& RequestParts)
{
    if (RequestParts.size() < 3)
    {
        statusMessage = "Invalid request. Please provide account number and transaction amount.";
        sendMessage(statusMessage);
        return;
    }

    QString accountNumber = RequestParts[1];
    QString amount = RequestParts[2];

    // Validate the amount
    bool isNumber;
    int transactionAmount = amount.toInt(&isNumber);
    if (!isNumber)
    {
        statusMessage = "Invalid transaction amount.";
        sendMessage(statusMessage);
        return;
    }

    bool success;
    if (transactionAmount < 0)
    {
        QString withdrawAmount = amount.mid(1);
        success = dataBase.withdrawMoney(accountNumber, withdrawAmount, statusMessage);
        Logger::instance().logMessage(statusMessage);
    }
    else if (transactionAmount > 0)
    {
        success = dataBase.depositMoney(accountNumber, amount, statusMessage);
        Logger::instance().logMessage(statusMessage);
    }
    else
    {
        statusMessage = "Transaction amount cannot be zero.";
        sendMessage(statusMessage);
        return;
    }

    if (success)
    {
        sendMessage("Transaction successful: " + statusMessage);
    }
    else
    {
        sendMessage("Transaction failed: " + statusMessage);
    }
}

void ServerHandler::makeTransfer(const QStringList &RequestParts)
{
    if (RequestParts.size() != 4)
    {
        statusMessage = "Invalid request.";
        sendMessage(statusMessage);
    }

    QString sourceAccountNumber = RequestParts[1];
    QString targetAccountNumber = RequestParts[2];
    QString amountStr = RequestParts[3];

    // Validate that the account numbers are digits only
    QRegularExpression accountNumberRegex("^\\d+$");
    if (!accountNumberRegex.match(sourceAccountNumber).hasMatch() || !accountNumberRegex.match(targetAccountNumber).hasMatch())
    {
        statusMessage = "Invalid account number format.";
        sendMessage(statusMessage);
        return;
    }

    // Validate the amount
    bool isNumber;
    int amount = amountStr.toInt(&isNumber);
    if (!isNumber || amount <= 0)
    {
        statusMessage = "Invalid transfer amount.";
        sendMessage(statusMessage);
        return;
    }

    // Ensure source and target account numbers are not the same
    if (sourceAccountNumber == targetAccountNumber)
    {
        statusMessage ="Source and target account numbers cannot be the same.";
        sendMessage(statusMessage);
        return;
    }

    QString statusMessage;
    bool success = dataBase.transferMoney(sourceAccountNumber, targetAccountNumber,amountStr,amountStr, statusMessage);
    Logger::instance().logMessage(statusMessage);

    if (success)
    {
        Logger::instance().logMessage("Transfer successful: " + statusMessage);
    }
    else
    {
        Logger::instance().logMessage("Transfer failed: " + statusMessage);
    }

    // Send a response back to the client
    QString responseMessage = QString("TransferResult:%1").arg(statusMessage);
    sendMessage(responseMessage);
}



void ServerHandler::sendMessage(QString Message)
{
    if (Socket->isOpen())
    {
        Socket->write(Message.toUtf8());
        QString logMessage = QString("My server Send Data to User: %1 Data => %2").arg(ID).arg(Message);
        Logger::instance().logMessage(logMessage);
    }
    else
    {
        QString logMessage = QString("Myserver Can't Send Data to User: %1 Because The Socket is Closed").arg(ID);
        Logger::instance().logMessage(logMessage);
    }
}
