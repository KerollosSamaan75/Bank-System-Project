#ifndef MAKETRANSFERHANDLER_H
#define MAKETRANSFERHANDLER_H

#include "RequestHandler.h"
#include "SendEmail.h"
#include "BankDataBase.h"

// The MakeTransferHandler class handles requests to transfer money between accounts in the bank system.
// It inherits from RequestHandler and overrides the execute method to perform the transfer operation.

class MakeTransferHandler : public RequestHandler
{
public:
    // Constructor that takes a reference to a BankDataBase object.
    // Initializes the dataBase member with the provided database reference.
    MakeTransferHandler(BankDataBase &db);

    // Overrides the execute method from RequestHandler.
    // This method takes the request parts and a reference to a status message string.
    // It processes the request to transfer money between accounts and updates the status message accordingly.
    void execute(const QStringList &RequestParts, QString &statusMessage) override;

private:
    // Reference to the BankDataBase object used for performing transfer operations.
    BankDataBase &dataBase;

    // Email utility object to send transaction notification emails.
    SendEmail email;

    // Private method to send an email notification about the transfer.
    // Parameters:
    // - sourceAccountNumber: The account number from which the transfer originates.
    // - targetAccountNumber: The account number to which the transfer is made.
    // - amountStr: The amount of money involved in the transfer as a QString.
    void sendEmail(const QString &sourceAccountNumber, const QString &targetAccountNumber, const QString &amountStr);
};

#endif // MAKETRANSFERUPS_HANDLER_H
