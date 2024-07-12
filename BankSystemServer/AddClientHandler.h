#ifndef ADDCLIENTHANDLER_H
#define ADDCLIENTHANDLER_H

#include "RequestHandler.h"
#include "BankDataBase.h"

class AddClientHandler : public RequestHandler
{
public:
    AddClientHandler(BankDataBase &db);
    void execute(const QStringList &RequestParts, QString &status) override;

private:
    BankDataBase &dataBase;
};


#endif // ADDCLIENTHANDLER_H
