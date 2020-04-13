#include "FamillyAccount.h"

json FamillyAccount::SerializeToJson()
{
    json j {Account::SerializeToJson()};

    j["memberIdList"] = memberIdList;

    return j;
}
