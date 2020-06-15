#ifndef ACCOUNTTYPE_H
#define ACCOUNTTYPE_H

#include <string>
#include <list>

using std::string;
using std::list;

class AccountType
{
public:
    enum Value : uint8_t
    {
        PERSONAL,
        SAVINGS,
        CHILD,
        CURRENCY,
        FAMILY,
        FIRM
    };
    AccountType() = default;
    AccountType(Value p_value) : value(p_value) {}
    AccountType(int p_value) { value = static_cast<Value>(p_value); }
    operator Value() const { return value; }
    operator int() const { return value; }
//    operator bool() = delete;
    bool operator==(AccountType aT) const { return value == aT.value; }
    bool operator!=(AccountType aT) const { return value != aT.value; }
    string ToString() {
        switch (value) {
            case PERSONAL: return "personal";
            case SAVINGS: return "savings";
            case CHILD: return "child";
            case FAMILY: return "family";
            case CURRENCY: return "currency";
            case FIRM: return "firm";
        }
    }

    static list<AccountType> GetAllTypesList() {
        return { AccountType::PERSONAL, AccountType::SAVINGS, AccountType::CHILD,
                 /*AccountType::CURRENCY,*/ AccountType::FAMILY/*, AccountType::FIRM*/ };
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

#endif // ACCOUNTTYPE_H
