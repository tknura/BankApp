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
