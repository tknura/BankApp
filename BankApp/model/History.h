#ifndef HISTORY_H
#define HISTORY_H

#include "Payment.h"
#include <list>

class History
{
private:
    std::list<std::shared_ptr<Payment>> paymentList;

public:
    History();
    void AddNode(std::shared_ptr<Payment> p_payment)
    {
//        auto p = std::make_shared<Payment>(p_payment);
        paymentList.push_back(p_payment);
    }

    json SerializeToJson();
};

#endif // HISTORY_H
