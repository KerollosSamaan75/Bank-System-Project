#ifndef MAKETRANSFERHANDLER_H
#define MAKETRANSFERHANDLER_H

#include "RequestHandler.h"
#include "SendEmail.h"
#include "BankDataBase.h"

class MakeTransferHandler : public RequestHandler
{
public:
    MakeTransferHandler(BankDataBase &db);
    void execute(const QStringList &RequestParts, QString &statusMessage) override;
private:
    BankDataBase &dataBase;
    SendEmail email;
    void sendEmail(const QString &sourceAccountNumber, const QString &targetAccountNumber, const QString &amountStr);
};

#endif // MAKETRANSFERHANDLER_H
