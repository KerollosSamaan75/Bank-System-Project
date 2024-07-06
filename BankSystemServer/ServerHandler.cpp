#include "ServerHandler.h"

ServerHandler::ServerHandler(qint32 ID,QObject *parent)
    : QThread{parent}
{
    this->ID = ID;
}

// ServerHandler::~ServerHandler()
// {
//     dataBase.setUserLoginState(userName, "0");
// }

void ServerHandler::run()
{
    qDebug()<<"User with ID: "<<ID<<" is running on thread "<<QThread::currentThreadId()<<Qt::endl;
    Socket = new QTcpSocket();
    Socket->setSocketDescriptor(ID);
    connect(Socket,&QTcpSocket::readyRead,this,&ServerHandler::onReadyRead,Qt::DirectConnection);
    connect(Socket,&QTcpSocket::disconnected,this,&ServerHandler::onDisconnected,Qt::DirectConnection);

    dataBase.initializeMainDatabase();
    dataBase.initializeTransactionDatabase();
    exec();
}

void ServerHandler::onReadyRead()
{
    QByteArray ByteArr = Socket->readAll();
    qDebug()<<"My Server Received Data From User:"<<ID<<" Data => "<<ByteArr<<Qt::endl;
    Operation(QString(ByteArr));
}

void ServerHandler::Operation(QString Request)
{
    QStringList List= Request.split(":");
    if(List[0] == "Login")
    {
        loginToServer(List);
    }
    if(List[0]=="AddAccount")
    {
        addNewClient(List);
    }
    if(List[0]=="GetAccountNumber")
    {
        getClientAccountNumber(List);
    }
    if(List[0]=="DeleteAccount")
    {
        deleteClientAccount(List);
    }
    if(List[0]=="GetAccountBalance")
    {
        getClientAccountBalance(List);
    }
    if(List[0]=="ViewTransactions")
    {
        getClientTransactionHistory(List);
    }
    if(List[0]=="ViewBankDatabase")
    {
        getBankDataBase(List);
    }
    if(List[0]=="UpdateAccount")
    {
        updateClientAccount(List);
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
            if (record["Login"].toString() == "0")
            {
                isUserValid = true;
                userAuthority = record["Authority"].toString(); // Capture user authority
                userAccountNumber = record["AccountNumber"].toString();
                break;
            }
            else
            {
                sendMessage("Login failed. This account is already logged in.");
                return;
            }
        }
    }
    
    if (isUserValid)
    {
        // Change the 'log' state in the database
        userName = tempName;
        password = tempPass;
        if (dataBase.setUserLoginState(userName, "1"))
        {
            QString successMessage = QString("%1:%2:%3").arg(userAuthority,userName,userAccountNumber);
            sendMessage(successMessage);
        }
        else
        {
            sendMessage("Login failed. Could not update the login state.");
        }
    }
    else
    {
        sendMessage("Login failed. Incorrect username or password.");
    }
}

void ServerHandler::addNewClient(const QStringList &RequestParts)
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
    if (dataBase.addClient(userName,password,fullName,ageStr,email,balanceStr))
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

void ServerHandler::getClientAccountNumber(const QStringList &RequestParts)
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

void ServerHandler::deleteClientAccount(const QStringList &RequestParts)
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

void ServerHandler::getClientAccountBalance(const QStringList &RequestParts)
{
    // Ensure RequestParts has the necessary elements
    if (RequestParts.size() < 2)
    {
        sendMessage("Invalid request. Please provide the username or account number.");
        return;
    }

    QString accountNumber = RequestParts[1]; // Assuming the identifier ( account number) is in RequestParts[1]
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
    QString responseMessage = "AdTransactionHistory:" + QString(doc.toJson(QJsonDocument::Compact));
    sendMessage(responseMessage);
}

void ServerHandler::getBankDataBase(const QStringList &RequestParts)
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
void ServerHandler::updateClientAccount(const QStringList &RequestParts)
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



void ServerHandler::onDisconnected()
{
    if(Socket->isOpen())
    {
        dataBase.setUserLoginState(userName, "0");
        Socket->close();
        qDebug()<<"Client => "<<ID<<"has disconnected"<<Qt::endl;
    }
}

void ServerHandler::sendMessage(QString Message)
{
    if(Socket->isOpen())
    {
        Socket->write(Message.toUtf8());
        qDebug()<<"My server Send Data to User:"<<ID<<" Data => "<<Message<<Qt::endl;
    }
    else
    {
        qDebug()<<"Myserver Can't Send Data to User:"<<ID<<"Because The Socket is Closed"<<Qt::endl;
    }
}


