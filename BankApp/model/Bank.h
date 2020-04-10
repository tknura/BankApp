#ifndef BANK_H
#define BANK_H

#include "User.h"
#include "Admin.h"
#include "Config.h"
#include "Account.h"
#include "Fund.h"
#include <iostream>
#include <map>
#include <list>
#include <random>
#include <memory>

using std::map;
using std::list;

class Bank
{
public:
    static map<std::string, Account> accountMap;
    static list<std::string> accountNumList;
    static map<std::string,Fund> fundMap;
    static list<std::string> fundNumList;
    static std::shared_ptr<IUser> currentlyLoggedUser;

    //variables used for generating random numbers
    static std::random_device rd;
    static std::mt19937 mt;

    static void LogIn(std::shared_ptr<IUser> data);
    static void Start();
};

#endif // BANK_H
