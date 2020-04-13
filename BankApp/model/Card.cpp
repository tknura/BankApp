#include "Card.h"

json Card::SerializeToJson()
{
    json j{};

    j["type"] = type;
    j["accNumber"] = accountNumber;
    j["number"] = number;
    j["ccv"] = ccv;
    j["transactionLimit"] = transactionLimit;

    return j;
}

