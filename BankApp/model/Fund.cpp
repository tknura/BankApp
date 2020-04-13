#include "Fund.h"


std::ostream& Fund::serialize(std::ostream&ss) const
{
    ss<<"minimum Amount:"<<minAmount<<"\n"
            <<"maximum Rate:"<<maxRate<<"\n"
           <<"fee:"<<fee<<"\n"
          <<"balance:"<<balance<<"\n";
    return ss;
}
std::ostream& operator<<(std::ostream&ss, const Fund&p_fund)
{
    p_fund.serialize(ss);
    return ss;
}

json Fund::SerializeToJson()
{
    json j{};

    j["type"] = type;
    j["minAmount"] = minAmount;
    j["maxRate"] = maxRate;
    j["fee"] = fee;
    j["balance"] = balance;
    j["ownerID"] = ownerId;

    return j;
}
