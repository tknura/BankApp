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
        paymentList.push_back(p_payment);
    }

    json SerializeToJson();

    int GetSize(){return paymentList.size();}



    std::list<std::shared_ptr<Payment>> GetList(){paymentList.sort
                ([](const std::shared_ptr<Payment> p_a,const std::shared_ptr<Payment> &p_b)
                {int a = std::stoi(p_a->GetDateStr().substr(0,4)+p_a->GetDateStr().substr(5,2)
                                                                +p_a->GetDateStr().substr(8,2));
                 int b = std::stoi(p_b->GetDateStr().substr(0,4)+p_b->GetDateStr().substr(5,2)
                                                                +p_b->GetDateStr().substr(8,2));
                return a>b; });
                                                 return paymentList;}
};

#endif // HISTORY_H
