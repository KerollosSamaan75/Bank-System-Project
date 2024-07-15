#ifndef LOGOUTHANDLER_H
#define LOGOUTHANDLER_H

#include "RequestHandler.h"
#include "BankDataBase.h"


class LogoutHandler : public RequestHandler
{
public:
    explicit LogoutHandler(BankDataBase &db);
    void execute(const QStringList &RequestParts, QString &statusMessage)override;

private:
    BankDataBase &dataBase;
};

#endif // LOGOUTHANDLER_H
