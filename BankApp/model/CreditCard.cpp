#include "CreditCard.h"

json CreditCard::SerializeToJson()
{
    json j{Card::SerializeToJson()};

    j["billingDate"] = billingDate;
    j["maxCredit"] = maxCredit;

    return j;
}
