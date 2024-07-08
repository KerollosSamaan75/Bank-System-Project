#ifndef UPDATEACCOUNTCOMMAND_H
#define UPDATEACCOUNTCOMMAND_H

#include "Command.h"
#include "BankDataBase.h"
#include "Logger.h"

class UpdateAccountCommand : public Command
{
public:
    UpdateAccountCommand(BankDataBase &db);
    void execute(const QStringList &RequestParts, QString &statusMessage) override;

private:
    BankDataBase &dataBase;
};

#endif // UPDATEACCOUNTCOMMAND_H
