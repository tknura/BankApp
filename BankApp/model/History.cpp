#include "History.h"

History::History()
{

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
