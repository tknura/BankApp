#ifndef BANK_H
#define BANK_H

#include "User.h"
#include "Account.h"
#include "Fund.h"
#include <map>

using std::map;

class Bank
{
public:
    Bank();
    map<std::string, Account> accountMap;
};

#endif // BANK_H
