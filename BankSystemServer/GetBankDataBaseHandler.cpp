#include "GetBankDataBaseHandler.h"

// Include the header file for GetBankDataBaseHandler class

GetBankDataBaseHandler::GetBankDataBaseHandler(BankDataBase &db) : dataBase(db) {}
// Constructor for GetBankDataBaseHandler class, initializing with a reference to BankDataBase instance

void GetBankDataBaseHandler::execute(const QStringList &RequestParts, QString &statusMessage)
{
    // Execute method that takes a QStringList RequestParts and QString statusMessage as parameters

    // Ensure the request is valid
    if (RequestParts.isEmpty() || RequestParts[0] != "GetBankDataBase")
    {
        statusMessage = "Invalid request. Expected 'GetBankDataBase'.";
        // If RequestParts is empty or the first element is not "GetBankDataBase", set statusMessage to indicate invalid request
        return;
    }

    // Get the bank database records
    QVector<QJsonObject> bankRecords = dataBase.getMainDatabase();
    // Retrieve the main database records from the BankDataBase instance

    // Prepare the response
    QJsonArray bankRecordsArray;
    for (const auto& record : bankRecords)
    {
        bankRecordsArray.append(record);
        // Append each record from bankRecords to bankRecordsArray
    }

    QJsonDocument doc(bankRecordsArray);
    // Create a JSON document from the bankRecordsArray

    statusMessage = "ViewBankDataBase:" + QString(doc.toJson(QJsonDocument::Compact));
    // Set statusMessage to indicate the response, including the JSON document converted to a compact JSON string
}
