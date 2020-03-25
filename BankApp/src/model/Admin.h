#ifndef ADMIN_H
#define ADMIN_H

#include "LogInData.h"
#include "Account.h"
#include "User.h"

class Admin : public LogInData
{
private:
    int currentId;

public:
    Admin();
    ~Admin();
    void CreateUser(LogInData &data, string email);
    //TODO end when account class is finished
    void AddAccount(User &user);
    //TODO end when card class is finished
    void AddCard(Account &account);
    //TODO end when fund class is finished
    void AddFund(User &fund);
};

#endif // ADMIN_H
