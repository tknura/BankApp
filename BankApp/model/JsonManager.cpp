#include "JsonManager.h"
#include "Config.h"
#include "SavingsFund.h"
#include "RetirementFund.h"
#include "ChildAccount.h"
#include "SavingsAccount.h"
#include "FamillyAccount.h"
#include "CreditCard.h"
#include "DebitCard.h"

#include <memory>

#include <fstream>

listP JsonManager::ParseFriendsData()
{
    listP friends{};
    std::ifstream f(Config::friendsJSONPath);

    if(f.is_open())
    {
        f>>friendsFile;
        f.close();

        for (const auto& person: friendsFile[userID]["friendsList"])
        {
            using str = std::string;

            str name = person["name"];

            str accNum = person["accNumber"];

            str address = person["address"];

            PaymentRetriever m(name, accNum, address);
            friends.push_back(m);
        }
    }
    else
    {
        throw std::runtime_error("Could not open the friendsData.json file");
    }

    return friends;
}
void JsonManager::ParseAccountData(listAcc& p_accountList, unorderedMapAcc& p_accountMap)
{
    std::ifstream f(Config::accountJSONPath);

    if(f.is_open())
    {
        f>>accountFile;
        f.close();

        std::shared_ptr<Account> p {nullptr};

        for(const auto& account: accountFile[0]["accounts"])
        {
            using str = std::string;


            str type {account["type"]};
            str number {account["number"]};
            int supervisorId {account["supervisorId"]};
            double balance  {account["balance"]};
            if(type == "personal")
            {
                p = std::make_shared<Account>(number,balance,supervisorId,type);
            }
            else if(type == "child")
            {
                int childId {account["childId"]};
                double dailyTransactionLimit {account["dailyTransactionLimit"]};
                p = std::make_shared<ChildAccount>(number,balance,supervisorId,dailyTransactionLimit,childId,type);
            }
            else if(type == "savings")
            {

                double interest {account["interest"]};
                p = std::make_shared<SavingsAccount>(number,balance,supervisorId,interest,type);
            }
            else if(type == "familly")
            {
                std::list<int> memberIdList {};
                for(const auto & id :account["memberIdList"])
                {
                    memberIdList.push_back((int)id);
                }
                p = std::make_shared<FamillyAccount>(number,balance,supervisorId,memberIdList,type);
            }
            p_accountList.push_back(number);//list with keys to the hash table
            p_accountMap.insert({number,p});
        }
    }
    else
    {
        throw std::runtime_error("Could not open the accountsData.json file");
    }
}
void JsonManager::ParseCardData(multiMapCard &p_map)
{
    std::ifstream f(Config::cardJSONPath);
    std::cerr<<Config::cardJSONPath<<"sranie";

    if(f.is_open())
    {
        f>>cardFile;
        f.close();

        std::shared_ptr<Card> p {nullptr};

        for(const auto& card :cardFile[0]["cards"])
        {
            str type {card["type"]};
            str accNumber {card["accNumber"]};
            str number {card["number"]};
            int ccv {card["ccv"]};
            double transactionLimit {card["transactionLimit"]};

            if(type == "prePaid")
            {
                p = std::make_shared<Card>(accNumber,number,ccv,transactionLimit,type);
            }
            else if(type == "credit")
            {
                double maxCredit {card["maxCredit"]};
                str billingDate {card["billingDate"]};
                p = std::make_shared<CreditCard>(accNumber,number,ccv,transactionLimit,maxCredit,billingDate,type);
            }
            else if(type == "debit")
            {
                double maxDebit {card["maxDebt"]};
                p = std::make_shared<DebitCard>(accNumber,number,ccv,transactionLimit,maxDebit,type);
            }
            p_map.insert({accNumber,p});
        }
    }
    else
    {
        throw std::runtime_error("Could not open the cardData.json file");
    }
}






void JsonManager::ParseFundData(multiMapFund &p_map)
{
    std::ifstream f(Config::fundJSONPath);

    if(f.is_open())
    {
        f>>fundsFile;
        f.close();

        std::shared_ptr<Fund> p {nullptr};

        for(const auto & fund:fundsFile[0]["fundsList"])
        {
            using str = std::string;
            str type {fund["type"]};
            double minAmount {fund["minAmount"]};
            double maxRate {fund["maxRate"]};
            double fee {fund["fee"]};
            double balance {fund["balance"]};
            int ownerId {fund["ownerID"]};
            if(type == "retirement")
            {
                bool isRetired {fund["isRetired"]};
                double monthlyTransferIn {fund["monthlyTransferIn"]};
                p = std::make_shared<RetirementFund>(minAmount,maxRate,fee,balance,isRetired,monthlyTransferIn,type,ownerId);
            }
            else if(type == "savings")
            {
                str startDate {fund["startDate"]};
                str endDate {fund["endDate"]};
                p = std::make_shared<SavingsFund>(minAmount,maxRate,fee,balance,startDate,endDate,type,ownerId);
            }
            p_map.insert({ownerId,p});
        }
    }
    else
    {
        throw std::runtime_error("Could not open the fundData.json file");
    }
}


void JsonManager::SerializeCardData(multiMapCard &p_map)
{
    std::string s{"[{\"cards\":["};
    for(auto it = p_map.begin(); it != p_map.end(); ++it)
    {
         s += (it->second)->SerializeToJson().dump();
         s += ",";
    }
    s.pop_back();
    s += "]}]";

    std::ofstream f(Config::cardJSONPath);
    if(f.is_open())
    {
        f<<s;
    }
    else
    {
        throw std::runtime_error("Could not open the cardData.json file");
    }

}


void JsonManager::SerializeAccountData(unorderedMapAcc& p_map)
{
    std::string s{"[{\"accounts\":["};
    for(auto it = p_map.begin(); it!=p_map.end(); ++it)
    {
        s += (it->second)->SerializeToJson().dump();
        s += ",";
    }
    s.pop_back();
    s += "]}]";

    std::ofstream f(Config::accountJSONPath);
    if(f.is_open())
    {
        f<<s;
    }
    else
    {
        throw std::runtime_error("Could not open the accountData.json file");
    }

}

void JsonManager::SerializeFundData(multiMapFund &p_map)
{
    std::string s{"[{\"fundsList\":["};
    for(auto it = p_map.begin(); it!=p_map.end(); ++it)
    {
        s += (it->second)->SerializeToJson().dump();
        s += ",";
    }
    s.pop_back();
    s += "]}]";

    std::ofstream f(Config::fundJSONPath);
    if(f.is_open())
    {
        f<<s;
    }
    else
    {
        throw std::runtime_error("Could not open the fundData.json file");
    }

}


