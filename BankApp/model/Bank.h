#ifndef BANK_H
#define BANK_H

#include "User.h"
#include "Admin.h"
#include "Config.h"
#include "Account.h"
#include "Fund.h"
#include <iostream>
#include <map>

using std::map;

class Bank
{
public:
    static map<std::string, Account> accountMap;
    static IUser *currentlyLoggedUser;
    static void LogIn(IUser* data);
    static void Start();
};

#endif // BANK_H
