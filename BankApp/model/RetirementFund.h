#ifndef RETIREMENTFUND_H
#define RETIREMENTFUND_H

#include <iostream>

#include "Fund.h"

class RetirementFund: public Fund
{
private:
    bool isRetired;
    double monthlyIn;
    double monthlyOut;
public:
    RetirementFund() = delete;

    RetirementFund(double p_minAmount, double p_maxRate, double p_fee, double p_balance, bool p_isRetired, double p_monthlyIn, int p_ownerId)
        :Fund(p_minAmount, p_maxRate, p_fee, p_balance,p_ownerId), isRetired(p_isRetired), monthlyIn(p_monthlyIn), monthlyOut(0){std::cerr<<"utworzono obiekt RetirementFund\n";}
    virtual std::ostream& serialize(std::ostream&ss) const override;
    void CalculateRetirement();

    json SerializeToJson() override;
    int GetType()override{return 1;}
};


#endif // RETIREMENTFUND_H
