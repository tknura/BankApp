#ifndef JSONMANAGER_H
#define JSONMANAGER_H

#include <list>
#include <map>

#include "PaymentRetriever.h"
#include "Account.h"
#include "Fund.h"

using list = std::list<PaymentRetriever>;
using mapAcc = std::map<std::string,Account>;
using mapFund = std::map<std::string,Fund>;


//class responsible for reading json files,
//createating data structures
//and passing them to the bank class.

class JsonManager
{
public:
    JsonManager();
    mapAcc ReadAccountData();
    mapFund ReadFundData();
    list ReadFriendsData();
    mapAcc WriteAccountData();
    mapFund WriteFundData();
    list WriteFriendsData();

};

#endif // JSONMANAGER_H
