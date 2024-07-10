#ifndef ADDCLIENTCOMMAND_H
#define ADDCLIENTCOMMAND_H

#include "Command.h"
#include "BankDataBase.h"

class AddClientCommand : public Command
{
public:
    AddClientCommand(BankDataBase &db);
    void execute(const QStringList &RequestParts, QString &status) override;

private:
    BankDataBase &dataBase;
};


#endif // ADDCLIENTCOMMAND_H
