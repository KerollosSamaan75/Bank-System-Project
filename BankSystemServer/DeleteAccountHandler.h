#ifndef DELETEACCOUNTHANDLER_H
#define DELETEACCOUNTHANDLER_H

#include "RequestHandler.h"
#include "BankDataBase.h"

// The DeleteAccountHandler class handles requests to delete an account from the bank database.
// It inherits from RequestHandler and overrides the execute method to perform the account deletion.

class DeleteAccountHandler : public RequestHandler
{
public:
    // Constructor that takes a reference to a BankDataBase object.
    // Initializes the dataBase member with the provided database reference.
    DeleteAccountHandler(BankDataBase &db);

    // Overrides the execute method from RequestHandler.
    // This method takes the request parts and a reference to a status message string.
    // It processes the request to delete an account and updates the status message accordingly.
    void execute(const QStringList &RequestParts, QString &statusMessage) override;

private:
    // Reference to the BankDataBase object where the account will be deleted.
    BankDataBase &dataBase;
};

#endif // DELETEACCOUNTHANDLER_H
