#ifndef CARD_H
#define CARD_H

#include <string>
#include <iostream>

#include "json.hpp"

using json = nlohmann::json;

class Card
{
private:
    std::string type;
    std::string accountNumber;
    std::string number;
    int ccv;
    double transactionLimit;
public:
    Card(std::string p_accountNumber, std::string p_number, int p_ccv, double p_transactionLimit,std::string p_type)
        :accountNumber(p_accountNumber), number(p_number), ccv(p_ccv), transactionLimit(p_transactionLimit),type(p_type){std::cerr<<"utworzono obiket Card\n";}
    virtual json SerializeToJson();

};

#endif // CARD_H
