#include "History.h"

History::History()
{
    std::cerr<<"History object created\n";
}

json History::SerializeToJson()
{
    json j = json::array();
    for(const auto& p :paymentList)
    {
        j+= (*p).SerializeToJson();
    }
    return j;
}

//bool SortCompare(std::shared_ptr<Payment> p_a, std::shared_ptr<Payment> &p_b)
//{
//    int a = std::stoi(p_a->GetDateStr().substr(0,4)
//                          +p_a->GetDateStr().substr(5,2)
//                          +p_a->GetDateStr().substr(8,2));
//    int b = std::stoi(p_b->GetDateStr().substr(0,4)
//                          +p_b->GetDateStr().substr(5,2)
//                          +p_b->GetDateStr().substr(8,2));
//    return a<b;
//}
