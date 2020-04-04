#ifndef PAYMENT_H
#define PAYMENT_H

#include <string>
#include "PaymentRetriever.h"
#include "IValidator.h"

using std::string;

class Payment : IValidator
{
public:
    Payment();
    ~Payment() override;
    float amount;
    string title;
    PaymentRetriever retriever;
    bool IsValid() override;
};

#endif // PAYMENT_H
