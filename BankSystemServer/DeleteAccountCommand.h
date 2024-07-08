#ifndef DELETEACCOUNTCOMMAND_H
#define DELETEACCOUNTCOMMAND_H

#include "Command.h"
#include "BankDataBase.h"
#include "Logger.h"

class DeleteAccountCommand : public Command
{
public:
    DeleteAccountCommand(BankDataBase &db);
    void execute(const QStringList &RequestParts, QString &statusMessage) override;

private:
    BankDataBase &dataBase;
};

#endif // DELETEACCOUNTCOMMAND_H
