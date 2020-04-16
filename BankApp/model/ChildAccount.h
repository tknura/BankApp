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

    ChildAccount(std::string p_number, double p_balance, int p_supervisorId, double p_dailyTransactionLimit, int p_childId)
        :Account(p_number, p_balance, p_supervisorId), dailyTransactionLimit(p_dailyTransactionLimit), childId(p_childId){std::cerr<<"utworzono obiekt ChildAccount\n";}

    json SerializeToJson() override;

    int GetType()override {return 2;}
};

#endif // CHILDACCOUNT_H
