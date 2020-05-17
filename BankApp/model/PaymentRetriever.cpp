#include "PaymentRetriever.h"

json PaymentRetriever::SerializeToJson()
{
    json j{};
    j["name"] = name;
    j["accNumber"] = accNumber;
    j["address"] = address;

    return j;
}
