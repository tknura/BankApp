#include "SavingsFund.h"


std::ostream& SavingsFund::serialize(std::ostream&ss) const
{
    Fund::serialize(ss);
    ss<<"start Date::"<<startDate<<"\n"
     <<"end Date:"<<endDate<<"\n";
    return ss;
}

json SavingsFund::SerializeToJson()
{
    json j(Fund::SerializeToJson());

    j["startDate"] = startDate;
    j["endDate"] = endDate;

    return j;
}
