#include "Card.h"

json Card::SerializeToJson()
{
    json j{};

    j["accNumber"] = accountNumber;
    j["number"] = number;
    j["ccv"] = ccv;
    j["transactionLimit"] = transactionLimit;

    return j;
}

