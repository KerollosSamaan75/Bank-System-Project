#ifndef MAKETRANSFERCOMMAND_H
#define MAKETRANSFERCOMMAND_H

#include "Command.h"
#include "SendEmail.h"
#include "BankDataBase.h"

class MakeTransferCommand : public Command
{
public:
    MakeTransferCommand(BankDataBase &db);
    void execute(const QStringList &RequestParts, QString &statusMessage) override;
private:
    BankDataBase &dataBase;
    SendEmail email;
    void sendEmail(const QString &sourceAccountNumber, const QString &targetAccountNumber, const QString &amountStr);
};

#endif // MAKETRANSFERCOMMAND_H
