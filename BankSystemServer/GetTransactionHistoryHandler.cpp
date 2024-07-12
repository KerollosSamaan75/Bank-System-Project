#include "GetTransactionHistoryHandler.h"

GetTransactionHistoryHandler::GetTransactionHistoryHandler(BankDataBase &db) : dataBase(db) {}

void GetTransactionHistoryHandler::execute(const QStringList &RequestParts, QString &statusMessage)
{
    // Ensure RequestParts has the necessary elements
    if (RequestParts.size() < 3)
    {
        statusMessage = "Invalid request. Please provide account number and history count.";
        return;
    }

    QString accountNumber = RequestParts[1]; // Assuming account number is in RequestParts[1]
    bool isNumber;
    int historyCount = RequestParts[2].toInt(&isNumber);

    // Validate the history count
    if (!isNumber || historyCount <= 0 || historyCount > 20)
    {
        statusMessage = "Invalid history count. Please provide a number between 1 and 20.";
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
        statusMessage = "Account not found.";
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
}
