#ifndef PAYMENTRETRIEVER_H
#define PAYMENTRETRIEVER_H

#include <string>
#include <iostream>

#include "json.hpp"

using std::string;
using json = nlohmann::json;

class PaymentRetriever
{
public:
    PaymentRetriever(string p_name, string p_accNumber, string p_address)
        :name(p_name), accNumber(p_accNumber), address(p_address){std::cerr<<"ziomek zrobiony\n";}
    PaymentRetriever();
   // ~PaymentRetriever();
    string name;
    string accNumber;
    string address;
    string GetAccNumer(){return accNumber;}
    json SerializeToJson();
};

#endif // PAYMENTRETRIEVER_H
