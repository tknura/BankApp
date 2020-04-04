#ifndef FAMILLYACCOUNT_H
#define FAMILLYACCOUNT_H

#include <list>

#include "Account.h"

class FamillyAccount: public Account
{
private:
    std::list<int> memberIdList;
public:
    FamillyAccount() = delete;
    FamillyAccount(std::string p_number, double p_balance, int p_supervisorId, std::list<int> &p_memberIdList)
        :Account(p_number, p_balance, p_supervisorId), memberIdList(p_memberIdList){std::cerr<<"utworzono obiekt FamillyAccount\n";}
};

#endif // FAMILLYACCOUNT_H
