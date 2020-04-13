#include "DebitCard.h"


json DebitCard::SerializeToJson()
{
    json j{Card::SerializeToJson()};

    j["maxDebt"] = maxDebt;

    return j;
}
