#include "RetirementFund.h"

std::ostream& RetirementFund::serialize(std::ostream&ss) const
{
    Fund::serialize(ss);
    ss<<"isRetired:"<<isRetired<<"\n"
     <<"monthly transfer in:"<<monthlyIn<<"\n";
    return ss;
}

