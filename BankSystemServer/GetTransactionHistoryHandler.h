#ifndef GETTRANSACTIONHISTORYHANDLER_H
#define GETTRANSACTIONHISTORYHANDLER_H

#include "RequestHandler.h"
#include "BankDataBase.h"

// The GetTransactionHistoryHandler class handles requests to retrieve the transaction history for a specific account from the bank database.
// It inherits from RequestHandler and overrides the execute method to perform the transaction history retrieval.

class GetTransactionHistoryHandler : public RequestHandler
{
public:
    // Constructor that takes a reference to a BankDataBase object.
    // Initializes the dataBase member with the provided database reference.
    GetTransactionHistoryHandler(BankDataBase &db);

    // Overrides the execute method from RequestHandler.
    // This method takes the request parts and a reference to a status message string.
    // It processes the request to retrieve the transaction history for a specific account and updates the status message accordingly.
    void execute(const QStringList &RequestParts, QString &statusMessage) override;

private:
    // Reference to the BankDataBase object from which the transaction history will be retrieved.
    BankDataBase &dataBase;
};

#endif // GETTRANSACTIONHISTORYHANDLER_H
