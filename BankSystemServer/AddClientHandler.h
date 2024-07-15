#ifndef ADDCLIENTHANDLER_H
#define ADDCLIENTHANDLER_H

#include "RequestHandler.h"
#include "BankDataBase.h"

// The AddClientHandler class handles requests to add a new client to the bank database.
// It inherits from RequestHandler and overrides the execute method to perform the client addition.

class AddClientHandler : public RequestHandler
{
public:
    // Constructor that takes a reference to a BankDataBase object.
    // Initializes the dataBase member with the provided database reference.
    AddClientHandler(BankDataBase &db);

    // Overrides the execute method from RequestHandler.
    // This method takes the request parts and a reference to a status string.
    // It processes the request to add a new client and updates the status accordingly.
    void execute(const QStringList &RequestParts, QString &status) override;

private:
    // Reference to the BankDataBase object where the new client will be added.
    BankDataBase &dataBase;
};

#endif // ADDCLIENTHANDLER_H
