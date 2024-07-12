#ifndef DELETEACCOUNTHANDLER_H
#define DELETEACCOUNTHANDLER_H

#include "RequestHandler.h"
#include "BankDataBase.h"

class DeleteAccountHandler : public RequestHandler
{
public:
    DeleteAccountHandler(BankDataBase &db);
    void execute(const QStringList &RequestParts, QString &statusMessage) override;

private:
    BankDataBase &dataBase;
};

#endif // DELETEACCOUNTHANDLER_H
