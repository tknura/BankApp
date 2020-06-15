#ifndef CARDTYPE_H
#define CARDTYPE_H

#include <string>
#include <list>

using std::string;
using std::list;

class CardType
{
public:
    enum Value : uint8_t
    {
        PRE_PAID,
        DEBIT,
        CREDIT
    };
    CardType() = default;
    CardType(Value p_value) : value(p_value) {}
    operator Value() const { return value; }
   // operator bool() = delete;
    bool operator==(CardType cT) const { return value == cT.value; }
    bool operator!=(CardType cT) const { return value != cT.value; }
    string ToString() {
        switch (value) {
        case PRE_PAID: return "pre-paid";
        case DEBIT: return "debit";
        case CREDIT: return "credit";        
        }
    }

    static list<CardType> GetAllTypesList() {
        return { CardType::PRE_PAID, CardType::CREDIT, CardType::DEBIT };
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

#endif // CARDTYPE_H
