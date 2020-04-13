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
    FamillyAccount(std::string p_number, double p_balance, int p_supervisorId, std::list<int> &p_memberIdList,std::string p_type)
        :Account(p_number, p_balance, p_supervisorId,p_type), memberIdList(p_memberIdList){std::cerr<<"utworzono obiekt FamillyAccount\n";}

    json SerializeToJson() override;

};

#endif // FAMILLYACCOUNT_H
