#ifndef BANK_H
#define BANK_H

#include "User.h"
#include "Config.h"
#include "Account.h"
#include "Fund.h"
#include <iostream>
#include <map>
#include <list>

using std::map;
using std::list;

class Bank
{
public:
    static map<std::string, Account> accountMap;
    static list<std::string> accountNumList;
    static map<std::string,Fund> fundMap;
    static list<std::string> fundNumList;
    static IUser *currentlyLoggedUser;
    static void LogIn(IUser* data);
    static void Start();
};

#endif // BANK_H
