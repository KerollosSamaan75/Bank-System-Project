#ifndef GETBANKDATABASEHANDLER_H
#define GETBANKDATABASEHANDLER_H

#include "RequestHandler.h"
#include "BankDataBase.h"

class GetBankDataBaseHandler : public RequestHandler
{
public:
    GetBankDataBaseHandler(BankDataBase &db);
    void execute(const QStringList &RequestParts, QString &statusMessage) override;

private:
    BankDataBase &dataBase;
};

#endif // GETBANKDATABASEHANDLER_H
