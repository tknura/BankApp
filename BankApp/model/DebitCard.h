#ifndef DEBITCARD_H
#define DEBITCARD_H

#include "Card.h"

class DebitCard: public Card
{
private:
    double maxDebt;
public:
    DebitCard() = delete;
   // DebitCard(std::string p_accountNumber, std::string p_number, int p_ccv, double p_transactionLimit, double p_maxDebt,std::string p_type)
   //     :Card(p_accountNumber, p_number, p_ccv, p_transactionLimit,p_type), maxDebt(p_maxDebt){std::cerr<<"utworzono obiekt DebitCard\n";}
    DebitCard(std::string p_accountNumber, std::string p_number, int p_ccv, double p_transactionLimit, double p_maxDebt)
        :Card(p_accountNumber, p_number, p_ccv, p_transactionLimit), maxDebt(p_maxDebt){std::cerr<<"DebitCard object created\n";}
    json SerializeToJson() override;
    int GetType() override{return 0;}

};



#endif // DEBITCARD_H
