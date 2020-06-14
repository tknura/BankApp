#ifndef CREDITCARD_H
#define CREDITCARD_H

#include "Card.h"

class CreditCard: public Card
{
private:
    double maxCredit;
    std::string billingDate;
public:
    CreditCard() = delete;
  //  CreditCard(std::string p_accountNumber, std::string p_number, int p_ccv, double p_transactionLimit, double p_maxCredit, std::string p_billingDate,std::string p_type)
     //   :Card(p_accountNumber, p_number, p_ccv, p_transactionLimit,p_type), maxCredit(p_maxCredit), billingDate(p_billingDate){std::cerr<<"utworzono obiekt CreditCard\n";}
    CreditCard(std::string p_accountNumber, std::string p_number, int p_ccv, double p_transactionLimit, double p_maxCredit, std::string p_billingDate)
        :Card(p_accountNumber, p_number, p_ccv, p_transactionLimit), maxCredit(p_maxCredit), billingDate(p_billingDate){std::cerr<<"CreditCard object created\n";}

    json SerializeToJson() override;
    CardType GetType() override{return CardType::CREDIT;}

};

#endif // CREDITCARD_H
