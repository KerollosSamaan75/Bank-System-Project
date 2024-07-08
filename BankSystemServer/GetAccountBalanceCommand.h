#ifndef GETACCOUNTBALANCECOMMAND_H
#define GETACCOUNTBALANCECOMMAND_H

#include "Command.h"
#include "BankDataBase.h"
#include "Logger.h"

class GetAccountBalanceCommand : public Command
{
public:
    GetAccountBalanceCommand(BankDataBase &db);
    void execute(const QStringList &RequestParts, QString &statusMessage) override;

private:
    BankDataBase &dataBase;
};

#endif // GETACCOUNTBALANCECOMMAND_H
