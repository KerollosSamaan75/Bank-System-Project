#ifndef GETTRANSACTIONHISTORYCOMMAND_H
#define GETTRANSACTIONHISTORYCOMMAND_H

#include "Command.h"
#include "BankDataBase.h"
#include "Logger.h"

class GetTransactionHistoryCommand : public Command
{
public:
    GetTransactionHistoryCommand(BankDataBase &db);
    void execute(const QStringList &RequestParts, QString &statusMessage) override;

private:
    BankDataBase &dataBase;
};

#endif // GETTRANSACTIONHISTORYCOMMAND_H
