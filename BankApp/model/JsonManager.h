#ifndef JSONMANAGER_H
#define JSONMANAGER_H

#include <list>
#include <map>
#include <unordered_map>

#include "Config.h"
#include "PaymentRetriever.h"
#include "Account.h"
#include "Fund.h"
#include "model/json.hpp"

using json = nlohmann::json;
using listP = std::list<std::shared_ptr<PaymentRetriever>>;
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
    void ParseData(listAcc& p_list, unorderedMapAcc& p_map);
    void ParseData(multiMapFund &p_map);
    void ParseData(multiMapCard &p_map);
    void ParseData(listP &p_list);
    void SerializeData(listP& p_list);
    std::string GetCardFile(){return cardFile.dump();}

    template <class T>
    void SerializeData(T &p_map,std::string p_dir);

};
template <class T>
void JsonManager::SerializeData(T &p_map, std::string p_dir)
{
    std::string s{"[{\"items\":["};
    for(auto it = p_map.begin(); it != p_map.end(); ++it)
    {
         json j =(*(it->second)).SerializeToJson();
         j["type"] =it->second->GetType();
         s += j.dump();
         s += ",";
    }
    s.pop_back();
    s += "]}]";

    std::ofstream f(p_dir);
    if(f.is_open())
    {
        f<<s;
    }
    else
    {
        throw std::runtime_error("Could not open file");
    }
}


#endif // JSONMANAGER_H
