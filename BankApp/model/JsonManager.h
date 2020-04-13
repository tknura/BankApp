#ifndef JSONMANAGER_H
#define JSONMANAGER_H

#include <list>
#include <map>
#include <unordered_map>

#include "PaymentRetriever.h"
#include "Account.h"
#include "Fund.h"
#include "model/json.hpp"

using json = nlohmann::json;
using listP = std::list<PaymentRetriever>;
using listAcc = std::list<std::string>;
using listFund = std::list<Fund>;
using unorderedMapAcc = std::unordered_map<std::string,std::shared_ptr<Account>>;
using multiMapFund = std::multimap<int,std::shared_ptr<Fund>>;
using multiMapCard = std::multimap<std::string,std::shared_ptr<Card>>;//nie wiem czy nie zmienić ich na unordered map

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
    json cardFile;
public:
    JsonManager(int p_userID)
        :userID(p_userID), friendsFile(0), accountFile(0), fundsFile(0){}
    JsonManager() = delete;
    JsonManager(const JsonManager&) = delete;
    JsonManager& operator=(const JsonManager&) = delete;
    JsonManager(JsonManager&&) = delete;
    Account& operator=(JsonManager&&) = delete;
    ~JsonManager() = default;
    void ParseAccountData(listAcc& p_list, unorderedMapAcc& p_map);
    void ParseFundData(multiMapFund &p_map);
    void ParseCardData(multiMapCard &p_map);
    listP ParseFriendsData();
    std::string GetCardFile(){return cardFile.dump();}

    void SerializeAccountData(unorderedMapAcc& p_map);
    void SerializeFundData(multiMapFund &p_map);
    void SerializeFriendsData(listP &p_list);
    void SerializeCardData(multiMapCard &p_map);

};

#endif // JSONMANAGER_H
