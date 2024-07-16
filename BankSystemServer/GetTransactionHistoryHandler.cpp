#include "GetTransactionHistoryHandler.h"

// Include the header file for GetTransactionHistoryHandler class

GetTransactionHistoryHandler::GetTransactionHistoryHandler(BankDataBase &db) : dataBase(db) {}
// Constructor for GetTransactionHistoryHandler class, initializing with a reference to BankDataBase instance

void GetTransactionHistoryHandler::execute(const QStringList &RequestParts, QString &statusMessage)
{
    // Execute method that takes a QStringList RequestParts and QString statusMessage as parameters

    // Ensure RequestParts has the necessary elements
    if (RequestParts.size() < 3)
    {
        statusMessage = "Invalid request. Please provide account number and history count.";
        // If RequestParts has less than 3 elements, set statusMessage to indicate invalid request
        return;
    }

    QString accountNumber = RequestParts[1]; // Assuming account number is in RequestParts[1]
    bool isNumber;
    int historyCount = RequestParts[2].toInt(&isNumber);
    // Convert the third element of RequestParts to an integer for history count validation

    // Validate the history count
    if (!isNumber || historyCount <= 0 || historyCount > 20)
    {
        statusMessage = "Invalid history count. Please provide a number between 1 and 20.";
        // If historyCount is not a valid number or out of range, set statusMessage to indicate invalid history count
        return;
    }

    // Get the transaction database records
    QVector<QJsonObject> transactionRecords = dataBase.getTransactionDatabase();
    // Retrieve the transaction database records from the BankDataBase instance

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
        // If accountNumber not found in transaction records, set statusMessage to indicate account not found
        return;
    }

    // Get the transactions array
    QJsonArray transactionsArray = accountTransactions["Transactions"].toArray();
    // Retrieve the transactions array from accountTransactions

    // Prepare the response with recent transactions
    QJsonArray recentTransactions;
    int transactionsCount = transactionsArray.size();
    for (int i = transactionsCount - historyCount; i < transactionsCount; ++i)
    {
        if (i >= 0)
        {
            recentTransactions.push_front(transactionsArray[i]);
            // Append recent transactions from transactionsArray based on historyCount
        }
    }

    // Create JSON response object
    QJsonObject response;
    response["AccountNumber"] = accountNumber;
    response["RecentTransactions"] = recentTransactions;

    // Convert response object to JSON document and set statusMessage
    QJsonDocument doc(response);
    statusMessage = "TransactionHistory:" + QString(doc.toJson(QJsonDocument::Compact));
    // Set statusMessage to indicate the response, including the JSON document converted to a compact JSON string
}
