#ifndef CARDTYPE_H
#define CARDTYPE_H

#include "model/CreditCard.h"
#include "model/DebitCard.h"
#include <list>

using std::string;
using std::list;

class CardType
{
public:
    enum Value : uint8_t
    {
        DEBIT,
        CREDIT,
        PRE_PAID
    };
    CardType() = default;
    CardType(Value p_value) : value(p_value) {}
    operator Value() const { return value; }
    operator bool() = delete;
    bool operator==(CardType cT) const { return value == cT.value; }
    bool operator!=(CardType cT) const { return value != cT.value; }
    string ToString() {
        switch (value) {
        case DEBIT: return "debit";
        case CREDIT: return "credit";
        case PRE_PAID: return "pre paid";
        }
    }

    static list<CardType> GetAllTypesList() {
        return { CardType::DEBIT, CardType::CREDIT, CardType::PRE_PAID };
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
