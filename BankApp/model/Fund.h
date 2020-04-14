#ifndef FUND_H
#define FUND_H

#include <iostream>

#include "json.hpp"

using json = nlohmann::json;

class Fund
{
private:
    double minAmount;
    double maxRate;
    double fee;
    double balance;
    std::string type;
    int ownerId;
public:
    Fund() = default;
    Fund(double p_minAmount, double p_maxRate, double p_fee, double p_balance,std::string p_type,int p_ownerId)
        :minAmount(p_minAmount), maxRate(p_maxRate), fee(p_fee), balance(p_balance),type(p_type),ownerId(p_ownerId){std::cerr<<"utworzono obiek Fund\n";}
    Fund(double p_minAmount, double p_maxRate, double p_fee, double p_balance,int p_ownerId)
        :minAmount(p_minAmount), maxRate(p_maxRate), fee(p_fee), balance(p_balance),ownerId(p_ownerId){std::cerr<<"utworzono obiek Fund\n";}
    friend std::ostream& operator<<(std::ostream&ss, const Fund&p_fund);
    virtual std::ostream& serialize(std::ostream&ss)const;
    virtual json SerializeToJson();
};



#endif // FUND_H
