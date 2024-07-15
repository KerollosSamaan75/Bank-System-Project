#ifndef GETACCOUNTBALANCEHANDLER_H
#define GETACCOUNTBALANCEHANDLER_H

#include "RequestHandler.h"
#include "BankDataBase.h"

// The GetAccountBalanceHandler class handles requests to retrieve the balance of an account from the bank database.
// It inherits from RequestHandler and overrides the execute method to perform the balance retrieval.

class GetAccountBalanceHandler : public RequestHandler
{
public:
    // Constructor that takes a reference to a BankDataBase object.
    // Initializes the dataBase member with the provided database reference.
    GetAccountBalanceHandler(BankDataBase &db);

    // Overrides the execute method from RequestHandler.
    // This method takes the request parts and a reference to a status message string.
    // It processes the request to retrieve the account balance and updates the status message accordingly.
    void execute(const QStringList &RequestParts, QString &statusMessage) override;

private:
    // Reference to the BankDataBase object from which the account balance will be retrieved.
    BankDataBase &dataBase;
};

#endif // GETACCOUNTBALANCEHANDLER_H
