#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "Account.h"

class SavingsAccount: public Account
{
private:
    double interest;
public:
    SavingsAccount() = delete;
    SavingsAccount(History p_history,std::string p_number, double p_balance, int p_supervisorId, double p_interest)
        :Account(p_history, p_number, p_balance, p_supervisorId), interest(p_interest){std::cerr<<"SavingsAccount object created\n";}
    SavingsAccount(std::string p_number, double p_balance, int p_supervisorId, double p_interest)
        :Account(p_number, p_balance, p_supervisorId), interest(p_interest){std::cerr<<"SavingsAccount object created\n";}
    json SerializeToJson() override;

    AccountType GetType()override {return AccountType::SAVINGS;}

};

#endif // SAVINGSACCOUNT_H
