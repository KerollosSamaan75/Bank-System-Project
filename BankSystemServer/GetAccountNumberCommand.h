#ifndef GETACCOUNTNUMBERCOMMAND_H
#define GETACCOUNTNUMBERCOMMAND_H

#include "Command.h"
#include "BankDataBase.h"

class GetAccountNumberCommand :  public Command
{
public:
    GetAccountNumberCommand(BankDataBase &db);
    void execute(const QStringList &RequestParts, QString &statusMessage) override;

private:
    BankDataBase &dataBase;
};

#endif // GETACCOUNTNUMBERCOMMAND_H
