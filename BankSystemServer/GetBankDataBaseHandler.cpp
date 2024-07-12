#include "GetBankDataBaseHandler.h"

GetBankDataBaseHandler::GetBankDataBaseHandler(BankDataBase &db) : dataBase(db) {}

void GetBankDataBaseHandler::execute(const QStringList &RequestParts, QString &statusMessage)
{
    // Ensure the request is valid
    if (RequestParts.isEmpty() || RequestParts[0] != "GetBankDataBase")
    {
        statusMessage = "Invalid request. Expected 'GetBankDataBase'.";
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
    statusMessage = "ViewBankDataBase:" + QString(doc.toJson(QJsonDocument::Compact));
}
