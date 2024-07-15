#ifndef LOGINHANDLER_H
#define LOGINHANDLER_H

#include "RequestHandler.h"
#include "BankDataBase.h"

// The LoginHandler class handles requests to authenticate and log in a user.
// It inherits from RequestHandler and overrides the execute method to perform the login operation.

class LoginHandler : public RequestHandler
{
public:
    // Constructor that takes a reference to a BankDataBase object.
    // Initializes the dataBase member with the provided database reference.
    LoginHandler(BankDataBase &db);

    // Overrides the execute method from RequestHandler.
    // This method takes the request parts and a reference to a status message string.
    // It processes the request to authenticate and log in a user and updates the status message accordingly.
    void execute(const QStringList &RequestParts, QString &statusMessage) override;

private:
    // Reference to the BankDataBase object used for user authentication and login.
    BankDataBase &dataBase;
};

#endif // LOGINHANDLER_H
