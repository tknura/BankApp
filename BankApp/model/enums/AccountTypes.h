#ifndef ACCOUNTTYPES_H
#define ACCOUNTTYPES_H

#include "model/ChildAccount.h"
#include "model/FamillyAccount.h"
#include "model/SavingsAccount.h"

enum class AccountTypes
{
    PERSONAL,
    SAVINGS,
    CHILD,
    CURRENCY,
    FAMILY,
    FIRM
};

#endif // ACCOUNTTYPES_H
