#ifndef ACCOUNTTYPE_H
#define ACCOUNTTYPE_H

#include "model/ChildAccount.h"
#include "model/FamillyAccount.h"
#include "model/SavingsAccount.h"

using std::string;

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
    operator Value() const { return value; }
    operator bool() = delete;
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

private:
    Value value;
};

#endif // ACCOUNTTYPE_H
