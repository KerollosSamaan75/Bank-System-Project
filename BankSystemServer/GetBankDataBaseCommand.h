#ifndef GETBANKDATABASECOMMAND_H
#define GETBANKDATABASECOMMAND_H

#include "Command.h"
#include "BankDataBase.h"
#include "Logger.h"

class GetBankDataBaseCommand : public Command
{
public:
    GetBankDataBaseCommand(BankDataBase &db);
    void execute(const QStringList &RequestParts, QString &statusMessage) override;

private:
    BankDataBase &dataBase;
};

#endif // GETBANKDATABASECOMMAND_H
