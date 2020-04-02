#include "SavingsFund.h"


std::ostream& SavingsFund::serialize(std::ostream&ss) const
{
    Fund::serialize(ss);
    ss<<"start Date::"<<startDate<<"\n"
     <<"end Date:"<<endDate<<"\n";
    return ss;
}
