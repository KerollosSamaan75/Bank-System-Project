// LoginCommand.h
#ifndef LOGINCOMMAND_H
#define LOGINCOMMAND_H

#include "Command.h"
#include "BankDataBase.h"


class LoginCommand : public Command
{
public:
    LoginCommand(BankDataBase &db);
    void execute(const QStringList &RequestParts, QString &statusMessage) override;

private:
    BankDataBase &dataBase;
};

#endif // LOGINCOMMAND_H
