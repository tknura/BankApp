#include "SavingsAccount.h"


json SavingsAccount::SerializeToJson()
{
    json j {Account::SerializeToJson()};

    j["interest"] = interest;

    return j;
}

