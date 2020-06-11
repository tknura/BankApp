#ifndef IACCOUNT_H
#define IACCOUNT_H

#include "Card.h"
#include "Payment.h"
#include "History.h"

class IAccount
{
public:
    IAccount() = default;
    void virtual AddFunds(double) = 0;
    virtual void UpdateHistory(std::shared_ptr<Payment>) = 0;
    virtual int GetType() = 0;
    virtual double GetBalance() const = 0;
    virtual void SetBalance(double ) = 0;
    virtual History GetHistory() = 0;
    virtual json SerializeToJson() = 0;
};




#endif // IACCOUNT_H
