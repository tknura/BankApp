#ifndef FUND_H
#define FUND_H

#include <iostream>

class Fund
{
private:
    double minAmount;
    double maxRate;
    double fee;
    double balance;
public:
    Fund() = default;
    Fund(double p_minAmount, double p_maxRate, double p_fee, double p_balance)
        :minAmount(p_minAmount), maxRate(p_maxRate), fee(p_fee), balance(p_balance){std::cerr<<"utworzono obiek Fund\n";}
    friend std::ostream& operator<<(std::ostream&ss, const Fund&p_fund);
    virtual std::ostream& serialize(std::ostream&ss)const;
};



#endif // FUND_H
