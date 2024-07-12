#ifndef GETTRANSACTIONHISTORYHANDLER_H
#define GETTRANSACTIONHISTORYHANDLER_H

#include "RequestHandler.h"
#include "BankDataBase.h"

class GetTransactionHistoryHandler : public RequestHandler
{
public:
    GetTransactionHistoryHandler(BankDataBase &db);
    void execute(const QStringList &RequestParts, QString &statusMessage) override;

private:
    BankDataBase &dataBase;
};

#endif // GETTRANSACTIONHISTORYHANDLER_H
