#ifndef FUNDTYPES_H
#define FUNDTYPES_H

#include "model/RetirementFund.h"
#include "model/SavingsFund.h"
#include <list>

using std::string;
using std::list;

class FundType
{
public:
    enum Value : uint8_t
    {
        SAVINGS,
        RETIREMENT,
        INVESTMENT
    };
    FundType() = default;
    FundType(Value p_value) : value(p_value) {}
    operator Value() const { return value; }
    operator bool() = delete;
    bool operator==(FundType fT) const { return value == fT.value; }
    bool operator!=(FundType fT) const { return value != fT.value; }
    string ToString() {
        switch (value) {
        case SAVINGS: return "debit";
        case RETIREMENT: return "credit";
        case INVESTMENT: return "pre paid";
        }
    }

    static list<FundType> GetAllTypesList() {
        return { FundType::SAVINGS, FundType::RETIREMENT, FundType::INVESTMENT };
    }

    static list<string> GetAllTypesStringList() {
        list<string> result;
        for(auto e : GetAllTypesList()){
            result.push_back(e.ToString());
        }
        return result;
    }

private:
    Value value;
};

#endif // FUNDTYPES_H
