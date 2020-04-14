#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "Account.h"

class SavingsAccount: public Account
{
private:
    double interest;
public:
    SavingsAccount() = delete;
    SavingsAccount(std::string p_number, double p_balance, int p_supervisorId, double p_interest,std::string p_type)
        :Account(p_number, p_balance, p_supervisorId,p_type), interest(p_interest){std::cerr<<"utworzono obiket SavingsAccount\n";}

    SavingsAccount(std::string p_number, double p_balance, int p_supervisorId, double p_interest)
        :Account(p_number, p_balance, p_supervisorId), interest(p_interest){std::cerr<<"utworzono obiket SavingsAccount\n";}
    json SerializeToJson() override;


};

#endif // SAVINGSACCOUNT_H
