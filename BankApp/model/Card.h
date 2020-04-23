#ifndef CARD_H
#define CARD_H

#include <string>
#include <iostream>

#include "json.hpp"

using json = nlohmann::json;

class Card
{
private:
    std::string accountNumber;
    std::string number;
    int ccv;
    double transactionLimit;
public:
    Card(std::string p_accountNumber, std::string p_number, int p_ccv, double p_transactionLimit)
        :accountNumber(p_accountNumber), number(p_number), ccv(p_ccv), transactionLimit(p_transactionLimit){std::cerr<<"utworzono obiket Card\n";}
    virtual json SerializeToJson();
    virtual int GetType(){return 2;}

};

#endif // CARD_H