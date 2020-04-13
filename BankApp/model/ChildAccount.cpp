#include "ChildAccount.h"


json ChildAccount::SerializeToJson()
{
    json j {Account::SerializeToJson()};

    j["childId"] = childId;
    j["dailyTransactionLimit"] = dailyTransactionLimit;

    return j;
}
