#ifndef GETBANKDATABASEHANDLER_H
#define GETBANKDATABASEHANDLER_H

#include "RequestHandler.h"
#include "BankDataBase.h"

// The GetBankDataBaseHandler class handles requests to retrieve the entire bank database.
// It inherits from RequestHandler and overrides the execute method to perform the database retrieval.

class GetBankDataBaseHandler : public RequestHandler
{
public:
    // Constructor that takes a reference to a BankDataBase object.
    // Initializes the dataBase member with the provided database reference.
    GetBankDataBaseHandler(BankDataBase &db);

    // Overrides the execute method from RequestHandler.
    // This method takes the request parts and a reference to a status message string.
    // It processes the request to retrieve the entire bank database and updates the status message accordingly.
    void execute(const QStringList &RequestParts, QString &statusMessage) override;

private:
    // Reference to the BankDataBase object from which the entire database will be retrieved.
    BankDataBase &dataBase;
};

#endif // GETBANKDATABASEHANDLER_H
