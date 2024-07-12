#ifndef MAKETRANSACTIONHANDLER_H
#define MAKETRANSACTIONHANDLER_H

#include "RequestHandler.h"
#include "BankDataBase.h"
#include "SendEmail.h"


class MakeTransactionHandler : public RequestHandler
{
public:
    MakeTransactionHandler(BankDataBase &db);
    void execute(const QStringList &RequestParts, QString &statusMessage) override;

private:
    BankDataBase &dataBase;
    SendEmail email;
    void sendEmail(const QString &sourceAccountNumber,const QString &amountStr);
};

#endif // MAKETRANSACTIONHANDLER_H
