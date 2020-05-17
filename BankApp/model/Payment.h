#ifndef PAYMENT_H
#define PAYMENT_H

#include <string>
#include "PaymentRetriever.h"
#include "IValidator.h"
#include "json.hpp"

using str = std::string;

class Payment : IValidator
{
public:
    Payment();
    ~Payment() override;
    double amount;
    str title;
    str date;
    PaymentRetriever retriever;
    bool IsValid() override;

    Payment(double p_amount, str p_title, str p_date, str p_name, str p_accNum, str p_address)
        :amount(p_amount),title(p_title), date(p_date), retriever(p_name,p_accNum,p_address){std::cerr<<"Payment utworzony";}

    str GetAccNumber(){return retriever.GetAccNumer();}
    double GetAmount(){return amount;}

    json SerializeToJson();

};

#endif // PAYMENT_H
