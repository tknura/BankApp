#ifndef DEBITCARD_H
#define DEBITCARD_H

#include "Card.h"

class DebitCard: public Card
{
private:
    double maxDebt;
public:
    DebitCard() = delete;
    DebitCard(std::string p_accountNumber, std::string p_number, int p_ccv, double p_transactionLimit, double p_maxDebt)
        :Card(p_accountNumber, p_number, p_ccv, p_transactionLimit), maxDebt(p_maxDebt){std::cerr<<"utworzono obiekt DebitCard\n";}
};

#endif // DEBITCARD_H
