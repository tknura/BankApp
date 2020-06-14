#ifndef CARD_H
#define CARD_H

#include <string>
#include <iostream>
#include "json.hpp"
#include "enums/CardType.h"

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
        :accountNumber(p_accountNumber), number(p_number), ccv(p_ccv), transactionLimit(p_transactionLimit){std::cerr<<"Card object created\n";}
    virtual json SerializeToJson();
    virtual CardType GetType(){return CardType::PRE_PAID;}

    std::string GetAccountNumber() const;
    void SetAccountNumber(const std::string &value);
    static std::string GenerateNumber();
    static std::string GenerateCCV();
};

#endif // CARD_H
