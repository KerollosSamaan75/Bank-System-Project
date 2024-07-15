#ifndef GETACCOUNTNUMBERHANDLER_H
#define GETACCOUNTNUMBERHANDLER_H

#include "RequestHandler.h"
#include "BankDataBase.h"

// The GetAccountNumberHandler class handles requests to retrieve the account number associated with a specific client from the bank database.
// It inherits from RequestHandler and overrides the execute method to perform the account number retrieval.

class GetAccountNumberHandler : public RequestHandler
{
public:
    // Constructor that takes a reference to a BankDataBase object.
    // Initializes the dataBase member with the provided database reference.
    GetAccountNumberHandler(BankDataBase &db);

    // Overrides the execute method from RequestHandler.
    // This method takes the request parts and a reference to a status message string.
    // It processes the request to retrieve the account number and updates the status message accordingly.
    void execute(const QStringList &RequestParts, QString &statusMessage) override;

private:
    // Reference to the BankDataBase object from which the account number will be retrieved.
    BankDataBase &dataBase;
};

#endif // GETACCOUNTNUMBERHANDLER_H
