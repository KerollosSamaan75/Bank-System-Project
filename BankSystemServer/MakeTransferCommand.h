#ifndef MAKETRANSFERCOMMAND_H
#define MAKETRANSFERCOMMAND_H

#include "Command.h"
#include "BankDataBase.h"
#include "Logger.h"

class MakeTransferCommand : public Command
{
public:
    MakeTransferCommand(BankDataBase &db);
    void execute(const QStringList &RequestParts, QString &statusMessage) override;

private:
    BankDataBase &dataBase;
};

#endif // MAKETRANSFERCOMMAND_H
