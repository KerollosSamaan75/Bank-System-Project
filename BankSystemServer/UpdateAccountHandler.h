#ifndef UPDATEACCOUNTHANDLER_H
#define UPDATEACCOUNTHANDLER_H

#include "RequestHandler.h"
#include "BankDataBase.h"

class UpdateAccountHandler : public RequestHandler
{
public:
    UpdateAccountHandler(BankDataBase &db);
    void execute(const QStringList &RequestParts, QString &statusMessage) override;

private:
    BankDataBase &dataBase;
};

#endif // UPDATEACCOUNTHANDLER_H
