#ifndef JSONMANAGER_H
#define JSONMANAGER_H

#include <list>
#include <map>

#include "PaymentRetriever.h"
#include "Account.h"
#include "Fund.h"
#include "model/json.hpp"

using json = nlohmann::json;
using listP = std::list<PaymentRetriever>;
using listAcc = std::list<Account>;
using mapFund = std::map<std::string,Fund>;


//class responsible for reading json files,
//createating data structures
//and passing them to the bank class.

class JsonManager
{
private:
    int userID;//
    json friendsFile;//objects holding pre-parsed json files
    json accountFile;
    json fundsFile;
public:
    JsonManager(int p_userID)
        :userID(p_userID), friendsFile(0), accountFile(0), fundsFile(0){}
    JsonManager() = delete;
    JsonManager(const JsonManager&) = delete;
    JsonManager& operator=(const JsonManager&) = delete;
    JsonManager(JsonManager&&) = delete;
    Account& operator=(JsonManager&&) = delete;
    ~JsonManager() = default;
    listAcc ParseAccountData();
    mapFund ParseFundData();
    listP ParseFriendsData();
  //  listAcc SerializeAccountData();
    mapFund SerializeFundData();
    listP SerializeFriendsData();

};

#endif // JSONMANAGER_H
