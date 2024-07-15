#ifndef MAKETRANSACTIONHANDLER_H
#define MAKETRANSACTIONHANDLER_H

#include "RequestHandler.h"
#include "BankDataBase.h"
#include "SendEmail.h"

// The MakeTransactionHandler class handles requests to make transactions (e.g., money transfers) in the bank system.
// It inherits from RequestHandler and overrides the execute method to perform the transaction operation.

class MakeTransactionHandler : public RequestHandler
{
public:
    // Constructor that takes a reference to a BankDataBase object.
    // Initializes the dataBase member with the provided database reference.
    MakeTransactionHandler(BankDataBase &db);

    // Overrides the execute method from RequestHandler.
    // This method takes the request parts and a reference to a status message string.
    // It processes the request to make a transaction and updates the status message accordingly.
    void execute(const QStringList &RequestParts, QString &statusMessage) override;

private:
    // Reference to the BankDataBase object used for performing transaction operations.
    BankDataBase &dataBase;

    // Email utility object to send transaction notification emails.
    SendEmail email;

    // Private method to send an email notification about the transaction.
    // Parameters:
    // - sourceAccountNumber: The account number from which the transaction originates.
    // - amountStr: The amount of money involved in the transaction as a QString.
    void sendEmail(const QString &sourceAccountNumber, const QString &amountStr);
};

#endif // MAKETRANSACTIONHANDLER_H
