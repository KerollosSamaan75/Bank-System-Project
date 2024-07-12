#ifndef GETACCOUNTNUMBERHANDLER_H
#define GETACCOUNTNUMBERHANDLER_H

#include "RequestHandler.h"
#include "BankDataBase.h"

class GetAccountNumberHandler :  public RequestHandler
{
public:
    GetAccountNumberHandler(BankDataBase &db);
    void execute(const QStringList &RequestParts, QString &statusMessage) override;

private:
    BankDataBase &dataBase;
};

#endif // GETACCOUNTNUMBERHANDLER_H
