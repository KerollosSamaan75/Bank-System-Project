#ifndef MAKETRANSACTIONCOMMAND_H
#define MAKETRANSACTIONCOMMAND_H

#include "Command.h"
#include "BankDataBase.h"
#include "Logger.h"


class MakeTransactionCommand : public Command
{
public:
    MakeTransactionCommand(BankDataBase &db);
    void execute(const QStringList &RequestParts, QString &statusMessage) override;

private:
    BankDataBase &dataBase;
};

#endif // MAKETRANSACTIONCOMMAND_H
