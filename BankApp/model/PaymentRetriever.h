#ifndef PAYMENTRETRIEVER_H
#define PAYMENTRETRIEVER_H

#include <string>
#include <iostream>

#include "json.hpp"

using std::string;
using json = nlohmann::json;

class PaymentRetriever
{
private:
    string name;
    string accNumber;
    string address;
public:
    PaymentRetriever(string p_name, string p_accNumber, string p_address)
        :name(p_name), accNumber(p_accNumber), address(p_address){std::cerr<<"PaymentRetriver object created\n";}
    PaymentRetriever();
    string GetAccNumer(){return accNumber;}
    json SerializeToJson();
    std::string GetName(){return name;}
};

#endif // PAYMENTRETRIEVER_H
