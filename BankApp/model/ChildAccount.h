#ifndef CHILDACCOUNT_H
#define CHILDACCOUNT_H

#include <list>

#include "Account.h"

class ChildAccount: public Account
{
private:
    double dailyTransactionLimit;
    int childId;
public:
    ChildAccount() = delete ;
    ChildAccount(History p_history, std::string p_number, double p_balance, int p_supervisorId, double p_dailyTransactionLimit, int p_childId)
        :Account(p_history,p_number, p_balance, p_supervisorId), dailyTransactionLimit(p_dailyTransactionLimit), childId(p_childId){std::cerr<<"ChildAccount object created\n";}
    ChildAccount(std::string p_number, double p_balance, int p_supervisorId, double p_dailyTransactionLimit, int p_childId)
        :Account(p_number, p_balance, p_supervisorId), dailyTransactionLimit(p_dailyTransactionLimit), childId(p_childId){std::cerr<<"ChildAccount object created\n";}

    json SerializeToJson() override;

    AccountType GetType()override {return AccountType::CHILD;}
};

#endif // CHILDACCOUNT_H
