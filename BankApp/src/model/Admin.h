#ifndef ADMIN_H
#define ADMIN_H

#include "LogInData.h"
#include "Account.h"
#include "Authorization.h"
#include <fstream>

class Admin : public IUser, public LogInData
{
private:
    static int idProvider;
    bool SaveUser(User& user);

public:
    Admin(const LogInData &data);
    ~Admin() override;
    bool CreateUser(string p_login, string p_password, string p_email);
    //TODO end when account class is finished
    bool AddAccount(User &user);
    //TODO end when card class is finished
    bool AddCard(Account &account);
    //TODO end when fund class is finished
    bool AddFund(User &fund);

    void OnLogIn() override;
//    bool IsValid() override;
};

#endif // ADMIN_H
