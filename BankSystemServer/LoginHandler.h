// LoginCommand.h
#ifndef LOGINHANDLER_H
#define LOGINHANDLER_H

#include "RequestHandler.h"
#include "BankDataBase.h"


class LoginHandler : public RequestHandler
{
public:
    LoginHandler(BankDataBase &db);
    void execute(const QStringList &RequestParts, QString &statusMessage) override;

private:
    BankDataBase &dataBase;
};

#endif // LOGINHANDLER_H
