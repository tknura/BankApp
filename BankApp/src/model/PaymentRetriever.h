#ifndef PAYMENTRETRIEVER_H
#define PAYMENTRETRIEVER_H

#include <string>

using std::string;

class PaymentRetriever
{
public:
    PaymentRetriever(string p_name, string p_accNumber, string p_address)
        :name(p_name), accNumber(p_accNumber), address(p_address){}
    string name;
    string accNumber;
    string address;
};

#endif // PAYMENTRETRIEVER_H
