#ifndef PAYMENTRETRIEVER_H
#define PAYMENTRETRIEVER_H

#include <string>
#include <iostream>

using std::string;

class PaymentRetriever
{
public:
    PaymentRetriever(string p_name, string p_accNumber, string p_address)
        :name(p_name), accNumber(p_accNumber), address(p_address){std::cerr<<"ziomek zrobiony\n";}
    string name;
    string accNumber;
    string address;
};

#endif // PAYMENTRETRIEVER_H
