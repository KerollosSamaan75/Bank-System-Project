#include "ServerHandler.h"


ServerHandler::ServerHandler(qint32 ID, QObject *parent)
    : QThread(parent)
{
    this->ID = ID;
}

void ServerHandler::run()
{

    qDebug()<<"User with ID: "<<ID<<" is running on thread "<<QThread::currentThreadId()<<Qt::endl;

    Socket = new QTcpSocket();
    Socket->setSocketDescriptor(ID);
    connect(Socket, &QTcpSocket::readyRead, this, &ServerHandler::onReadyRead, Qt::DirectConnection);
    connect(Socket, &QTcpSocket::disconnected, this, &ServerHandler::onDisconnected, Qt::DirectConnection);

    dataBase.initializeMainDatabase();
    dataBase.initializeTransactionDatabase();
    exec();
}

void ServerHandler::onReadyRead()
{
    QByteArray ByteArr = Socket->readAll();
    QString logMessage = QString("My Server Received Data From User: %1 Data => %2").arg(ID).arg(QString(ByteArr));
    Logger::instance().logMessage(logMessage);
    qDebug() << logMessage;

    Operation(QString(ByteArr));
}

void ServerHandler::onDisconnected()
{
    if(Socket->isOpen())
    {
        Socket->close();
        qDebug()<<"Client => "<<ID<<"has disconnected"<<Qt::endl;
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
        sendMessage("Invalid request. Please provide username and password.");
        return;
    }

    const QString tempName = RequestParts[1];
    const QString tempPass = RequestParts[2];
    bool isUserValid = false;
    QString userAuthority;
    QString userAccountNumber;
    QVector<QJsonObject> databaseRecords = dataBase.getMainDatabase(); // Get the main database records

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

        QString successMessage = QString("%1:%2:%3").arg(userAuthority, userName, userAccountNumber);
        sendMessage(successMessage);
    }
    else
    {
        sendMessage("Login failed. Incorrect username or password.");
    }
}

void ServerHandler::addNewClient(const QStringList& RequestParts)
{
    // Ensure RequestParts has at least 7 elements
    if (RequestParts.size() < 7)
    {
        sendMessage("Invalid request. Please provide all required fields: full name, username, password, age, email, and balance.");
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
            sendMessage("This username is already taken. Please choose a different username.");
            return;
        }
    }

    // Add new user to the database
    if (dataBase.addClient(userName, password, fullName, ageStr, email, balanceStr))
    {
        QString successMessage = QString("Congratulations! New user '%1' has been added. Welcome aboard").arg(userName);
        sendMessage(successMessage);
    }
    else
    {
        QString failureMessage = QString("Sadly, new user '%1' couldn't be added to the database. Please try again.").arg(userName);
        sendMessage(failureMessage);
    }
}

void ServerHandler::getClientAccountNumber(const QStringList& RequestParts)
{
    // Ensure RequestParts has the necessary elements
    if (RequestParts.size() < 2)
    {
        sendMessage("Invalid request. Please provide username or identifier.");
        return;
    }

    QString username = RequestParts[1]; // Assuming username is in RequestParts[1]
    QVector<QJsonObject> databaseRecords = dataBase.getMainDatabase();

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
        QString response = QString("Account number for %1 is: %2").arg(username).arg(accountNumber);
        sendMessage(response);
    }
    else
    {
        // Send an error message if the username was not found
        sendMessage(QString("Account number for %1 not found.").arg(username));
    }
}

void ServerHandler::deleteClientAccount(const QStringList& RequestParts)
{
    // Ensure RequestParts has the necessary elements
    if (RequestParts.size() < 2)
    {
        sendMessage("Invalid request. Please provide the account number.");
        return;
    }

    QString accountNumber = RequestParts[1]; // Assuming account number is in RequestParts[1]

    // Attempt to delete the client from the database
    bool success = dataBase.deleteClient(accountNumber);

    if (success)
    {
        sendMessage(QString("Client account with account number %1 has been successfully deleted.").arg(accountNumber));
    }
    else
    {
        sendMessage(QString("Failed to delete client account with account number %1. The account may not exist.").arg(accountNumber));
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
    QVector<QJsonObject> databaseRecords = dataBase.getMainDatabase(); // Get the main database records

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
        QString successMessage = QString("The account balance for %1 is %2.").arg(userName, balance);
        sendMessage(successMessage);
    }
    else
    {
        sendMessage(QString("Client with account number %1 not found.").arg(accountNumber));
    }
}

void ServerHandler::getClientTransactionHistory(const QStringList& RequestParts)
{
    // Ensure RequestParts has the necessary elements
    if (RequestParts.size() < 3)
    {
        sendMessage("Invalid request. Please provide account number and history count.");
        return;
    }

    QString accountNumber = RequestParts[1]; // Assuming account number is in RequestParts[1]
    bool isNumber;
    int historyCount = RequestParts[2].toInt(&isNumber);

    // Validate the history count
    if (!isNumber || historyCount <= 0 || historyCount > 20)
    {
        sendMessage("Invalid history count. Please provide a number between 1 and 20.");
        return;
    }

    // Get the transaction database records
    QVector<QJsonObject> transactionRecords = dataBase.getTransactionDatabase();

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
        sendMessage("Account not found.");
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
    QString responseMessage = "TransactionHistory:" + QString(doc.toJson(QJsonDocument::Compact));
    sendMessage(responseMessage);
}

void ServerHandler::getBankDataBase(const QStringList& RequestParts)
{
    // Ensure the request is valid
    if (RequestParts.isEmpty() || RequestParts[0] != "ViewBankDatabase")
    {
        sendMessage("Invalid request. Expected 'ViewBankDatabase'.");
        return;
    }

    // Get the bank database records
    QVector<QJsonObject> bankRecords = dataBase.getMainDatabase();

    // Prepare the response
    QJsonArray bankRecordsArray;
    for (const auto& record : bankRecords)
    {
        bankRecordsArray.append(record);
    }

    QJsonDocument doc(bankRecordsArray);
    QString responseMessage = "ViewBankDataBase:" + QString(doc.toJson(QJsonDocument::Compact));
    sendMessage(responseMessage);
}

void ServerHandler::updateClientAccount(const QStringList& RequestParts)
{
    // Ensure RequestParts has the necessary elements
    if (RequestParts.size() < 7)
    {
        sendMessage("Invalid request. Please provide all required fields.");
        return;
    }

    QString fullName = RequestParts[1];
    QString userName = RequestParts[2];
    QString passWord = RequestParts[3];
    QString age = RequestParts[4];
    QString email = RequestParts[5];
    QString accountNumber = RequestParts[6];

    // Update the client account in the database
    bool success = dataBase.updateClient(accountNumber, userName, passWord, fullName, age, email);

    // Send appropriate response based on update result
    if (success)
    {
        sendMessage("Account update successful.");
    }
    else
    {
        sendMessage("Account update failed. Please check the account number and try again.");
    }
}

void ServerHandler::makeTransaction(const QStringList& RequestParts)
{
    if (RequestParts.size() < 3)
    {
        sendMessage("Invalid request. Please provide account number and transaction amount.");
        return;
    }

    QString accountNumber = RequestParts[1];
    QString amount = RequestParts[2];

    // Validate the amount
    bool isNumber;
    int transactionAmount = amount.toInt(&isNumber);
    if (!isNumber)
    {
        sendMessage("Invalid transaction amount.");
        return;
    }

    QString statusMessage;
    bool success;

    if (transactionAmount < 0)
    {
        QString withdrawAmount = amount.mid(1);
        success = dataBase.withdrawMoney(accountNumber, withdrawAmount, statusMessage);
    }
    else if (transactionAmount > 0)
    {
        success = dataBase.depositMoney(accountNumber, amount, statusMessage);
    }
    else
    {
        sendMessage("Transaction amount cannot be zero.");
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
        qDebug() << "Invalid number of arguments for makeTransfer.";
        return;
    }

    QString sourceAccountNumber = RequestParts[1];
    QString targetAccountNumber = RequestParts[2];
    QString amountStr = RequestParts[3];

    // Validate that the account numbers are digits only
    QRegularExpression accountNumberRegex("^\\d+$");
    if (!accountNumberRegex.match(sourceAccountNumber).hasMatch() || !accountNumberRegex.match(targetAccountNumber).hasMatch())
    {
        sendMessage("Invalid account number format.");
        return;
    }

    // Validate the amount
    bool isNumber;
    int amount = amountStr.toInt(&isNumber);
    if (!isNumber || amount <= 0)
    {
        sendMessage("Invalid transfer amount.");
        return;
    }

    // Ensure source and target account numbers are not the same
    if (sourceAccountNumber == targetAccountNumber)
    {
        sendMessage("Source and target account numbers cannot be the same.");
        return;
    }

    QString statusMessage;
    bool success = dataBase.transferMoney(sourceAccountNumber, targetAccountNumber,amountStr,amountStr, statusMessage);

    if (success)
    {
        qDebug() << "Transfer successful: " << statusMessage;
    }
    else
    {
        qDebug() << "Transfer failed: " << statusMessage;
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
        qDebug() << logMessage;
    }
    else
    {
        QString logMessage = QString("Myserver Can't Send Data to User: %1 Because The Socket is Closed").arg(ID);
        Logger::instance().logMessage(logMessage);
        qDebug() << logMessage;
    }
}
