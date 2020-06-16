#include "RetirementFund.h"

std::ostream& RetirementFund::serialize(std::ostream&ss) const
{
    Fund::serialize(ss);
    ss<<"isRetired:"<<isRetired<<"\n"
     <<"monthly transfer in:"<<monthlyIn<<"\n";
    return ss;
}

json RetirementFund::SerializeToJson()
{
    json j(Fund::SerializeToJson());

    j["isRetired"] = isRetired;
    j["monthlyTransferIn"] = monthlyIn;

    return j;
}
