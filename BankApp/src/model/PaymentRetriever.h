#ifndef PAYMENTRETRIEVER_H
#define PAYMENTRETRIEVER_H

#include <string>

using std::string;

class PaymentRetriever
{
public:
    PaymentRetriever(string, string, string);
    string name;
    string title;
    string adress;
};

#endif // PAYMENTRETRIEVER_H
