#ifndef UPDATEACCOUNTHANDLER_H
#define UPDATEACCOUNTHANDLER_H

#include "RequestHandler.h"
#include "BankDataBase.h"

// UpdateAccountHandler class handles requests to update client account information.
// It interacts with BankDataBase to perform updates and manages the response status.

class UpdateAccountHandler : public RequestHandler
{
public:
    // Constructor: Initializes an instance of UpdateAccountHandler.
    // Parameters:
    // - db: Reference to the BankDataBase instance for database operations.
    UpdateAccountHandler(BankDataBase &db);

    // Override of execute method from RequestHandler.
    // Processes the request to update client account information.
    // Parameters:
    // - RequestParts: Parts of the request parsed into a QStringList.
    // - statusMessage: Reference to a QString to update with the execution status or response.
    void execute(const QStringList &RequestParts, QString &statusMessage) override;

private:
    BankDataBase &dataBase; // Reference to the BankDataBase instance for database operations.
};

#endif // UPDATEACCOUNTHANDLER_H
