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
    CreditCard(std::string p_accountNumber, std::string p_number, int p_ccv, double p_transactionLimit, double p_maxCredit, std::string p_billingDate)
        :Card(p_accountNumber, p_number, p_ccv, p_transactionLimit), maxCredit(p_maxCredit), billingDate(p_billingDate){std::cerr<<"utworzono obiekt CreditCard\n";}
};

#endif // CREDITCARD_H
