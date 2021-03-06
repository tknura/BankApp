#ifndef FUNDTYPES_H
#define FUNDTYPES_H

#include <string>
#include <list>

using std::string;
using std::list;

class FundType
{
public:
    enum Value : uint8_t
    {
        INVESTMENT,
        SAVINGS,
        RETIREMENT
    };
    FundType() = default;
    FundType(Value p_value) : value(p_value) {}
    operator Value() const { return value; }
    //operator bool() = delete;
    bool operator==(FundType fT) const { return value == fT.value; }
    bool operator!=(FundType fT) const { return value != fT.value; }
    string ToString() {
        switch (value) {
        case SAVINGS: return "savings";
        case RETIREMENT: return "retirement";
        case INVESTMENT: return "investment";
        }
    }

    static list<FundType> GetAllTypesList() {
        return { /*FundType::INVESTMENT,*/ FundType::SAVINGS, FundType::RETIREMENT};
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
