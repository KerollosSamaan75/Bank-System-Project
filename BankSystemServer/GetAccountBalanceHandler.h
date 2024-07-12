#ifndef GETACCOUNTBALANCEHANDLER_H
#define GETACCOUNTBALANCEHANDLER_H

#include "RequestHandler.h"
#include "BankDataBase.h"

class GetAccountBalanceHandler : public RequestHandler
{
public:
    GetAccountBalanceHandler(BankDataBase &db);
    void execute(const QStringList &RequestParts, QString &statusMessage) override;

private:
    BankDataBase &dataBase;
};

#endif // GETACCOUNTBALANCEHANDLER_H
