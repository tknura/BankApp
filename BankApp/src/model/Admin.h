#ifndef ADMIN_H
#define ADMIN_H

#include "LogInData.h"
#include "Account.h"
#include "User.h"

class Admin : public LogInData
{
public:
    Admin();
    ~Admin();
    void CreateUser();
    void AddAccount(User);
    void AddCard(Account);
    void AddFund(User);
};

#endif // ADMIN_H
