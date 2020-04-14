#ifndef SAVINGSFUND_H
#define SAVINGSFUND_H

#include <string>

#include "Fund.h"

using str = std::string;


class SavingsFund: public Fund
{
private:
    str startDate;
    str endDate;

public:
    SavingsFund() = delete;

    SavingsFund(double p_minAmount, double p_maxRate, double p_fee, double p_balance, str p_startDate, str p_endDate, int p_ownerId)
        :Fund(p_minAmount, p_maxRate, p_fee, p_balance,p_ownerId), startDate(p_startDate), endDate(p_endDate){std::cerr<<"utworzono obiekt SavingsFund\n";}
    virtual std::ostream& serialize(std::ostream&ss) const override;

    json SerializeToJson() override;

    int GetType()override {return 0;}


};


#endif // SAVINGSFUND_H
