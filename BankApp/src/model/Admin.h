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
    Admin(std::string p_login, std::string p_password);
    Admin(const LogInData &data);
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
