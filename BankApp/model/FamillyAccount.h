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
    FamillyAccount(History p_history,std::string p_number, double p_balance, int p_supervisorId, std::list<int> &p_memberIdList)
        :Account(p_history, p_number, p_balance, p_supervisorId), memberIdList(p_memberIdList){std::cerr<<"FamillyAccount object created\n";}
    FamillyAccount(std::string p_number, double p_balance, int p_supervisorId, std::list<int> &p_memberIdList)
        :Account(p_number, p_balance, p_supervisorId), memberIdList(p_memberIdList){std::cerr<<"FamillyAccount  object created\n";}
    json SerializeToJson() override;

    int GetType()override {return 4;}

};

#endif // FAMILLYACCOUNT_H
