#ifndef ADMIN_H
#define ADMIN_H

#include "LogInData.h"
#include "Account.h"
#include "Bank.h"
#include "User.h"
#include <fstream>

class Admin : public LogInData, public IUser
{
private:
    static int currentId;

public:
    Admin(const LogInData &data);
    ~Admin() override;
    void CreateUser(LogInData &data, string email);
    //TODO end when account class is finished
    void AddAccount(User &user);
    //TODO end when card class is finished
    void AddCard(Account &account);
    //TODO end when fund class is finished
    void AddFund(User &fund);

    bool IsValid() override;
};

#endif // ADMIN_H