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

void JsonManager::ParseData(listP & p_list)
{

    std::ifstream f(Config::friendsJSONPath);

    if(f.is_open())
    {
        f>>friendsFile;
        f.close();

        std::shared_ptr<PaymentRetriever> p {nullptr};

        for (const auto& person: friendsFile[userID]["items"])//tu jest błąd powinno być friends data
        {
            using str = std::string;

            str name = person["name"];
            str accNum = person["accNumber"];
            str address = person["address"];

            p = std::make_shared<PaymentRetriever>(name,accNum,address);

            p_list.push_back(p);
        }
    }
    else
    {
        throw std::runtime_error("Could not open the friendsData.json file");
    }
}
void JsonManager::ParseData(listAcc& p_accountList, unorderedMapAcc& p_accountMap)
{
    std::ifstream f(Config::accountJSONPath);

    if(f.is_open())
    {
        f>>accountFile;
        f.close();

        std::shared_ptr<Account> p {nullptr};
        std::shared_ptr<Payment> t {nullptr};


        for(const auto& account: accountFile[0]["items"])
        {
            using str = std::string;


            int type {account["type"]};
            str number {account["number"]};
            int supervisorId {account["supervisorId"]};
            double balance  {account["balance"]};
            //--------loading history--------
            double h_amount{};
            str h_title{};
            str h_date{};
            //===payment retriever===
            str hp_name{};
            str hp_accNumber{};
            str hp_address{};
            //=======================
            History tmpHistory {};
             for(const auto & history:account["history"])
            {
                h_amount = history["amount"];
                h_title = history["title"];
                h_date = history["date"];
                hp_name = history["name"];
                hp_accNumber = history["accNumber"];
                hp_address = history["address"];
                t = std::make_shared<Payment>(h_amount,h_title, h_date, hp_name, hp_accNumber, hp_address);
                tmpHistory.AddNode(t);
            }
            //-------------------------------
            if(type == 0)
            {
                p = std::make_shared<Account>(tmpHistory,number,balance,supervisorId);
            }
            else if(type == 2)
            {
                int childId {account["childId"]};
                double dailyTransactionLimit {account["dailyTransactionLimit"]};
                p = std::make_shared<ChildAccount>(tmpHistory,number,balance,supervisorId,dailyTransactionLimit,childId);
            }
            else if(type == 1)
            {

                double interest {account["interest"]};
                p = std::make_shared<SavingsAccount>(tmpHistory,number,balance,supervisorId,interest);
            }
            else if(type == 4)
            {
                std::list<int> memberIdList {};
                for(const auto & id :account["memberIdList"])
                {
                    memberIdList.push_back((int)id);
                }
                p = std::make_shared<FamillyAccount>(tmpHistory,number,balance,supervisorId,memberIdList);
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
void JsonManager::ParseData(multiMapCard &p_map)
{
    std::ifstream f(Config::cardJSONPath);
    std::cerr<<Config::cardJSONPath<<"sranie";

    if(f.is_open())
    {
        f>>cardFile;
        f.close();

        std::shared_ptr<Card> p {nullptr};

        for(const auto& card :cardFile[0]["items"])
        {
            int type {card["type"]};
            str accNumber {card["accNumber"]};
            str number {card["number"]};
            int ccv {card["ccv"]};
            double transactionLimit {card["transactionLimit"]};

            if(type == 2)
            {
                p = std::make_shared<Card>(accNumber,number,ccv,transactionLimit);
            }
            else if(type == 1)
            {
                double maxCredit {card["maxCredit"]};
                str billingDate {card["billingDate"]};
                p = std::make_shared<CreditCard>(accNumber,number,ccv,transactionLimit,maxCredit,billingDate);
            }
            else if(type == 0)
            {
                double maxDebit {card["maxDebt"]};
                p = std::make_shared<DebitCard>(accNumber,number,ccv,transactionLimit,maxDebit);
            }
            p_map.insert({accNumber,p});
        }
    }
    else
    {
        throw std::runtime_error("Could not open the cardData.json file");
    }
}






void JsonManager::ParseData(multiMapFund &p_map)
{
    std::ifstream f(Config::fundJSONPath);

    if(f.is_open())
    {
        f>>fundsFile;
        f.close();

        std::shared_ptr<Fund> p {nullptr};

        for(const auto & fund:fundsFile[0]["items"])
        {
            using str = std::string;
            int type {fund["type"]};
            double minAmount {fund["minAmount"]};
            double maxRate {fund["maxRate"]};
            double fee {fund["fee"]};
            double balance {fund["balance"]};
            int ownerId {fund["ownerID"]};
            if(type == 1)
            {
                bool isRetired {fund["isRetired"]};
                double monthlyTransferIn {fund["monthlyTransferIn"]};
                p = std::make_shared<RetirementFund>(minAmount,maxRate,fee,balance,isRetired,monthlyTransferIn,ownerId);
            }
            else if(type == 0)
            {
                str startDate {fund["startDate"]};
                str endDate {fund["endDate"]};
                p = std::make_shared<SavingsFund>(minAmount,maxRate,fee,balance,startDate,endDate,ownerId);
            }
            p_map.insert({ownerId,p});
        }
    }
    else
    {
        throw std::runtime_error("Could not open the fundData.json file");
    }
}
void JsonManager::SerializeData(listP& p_list)
{
    std::string s{"["};
    for(auto it = p_list.begin(); it!=p_list.end(); ++it)
    {
        json j = (*it)->SerializeToJson();
        s+= j.dump();
        s+= ",";
    }
    //std::cout<<s<<"\n";
    s.pop_back();
    s+= "]";
    std::cout<<s<<"\n";
    json j2 = json::parse(s);
    friendsFile[userID]["items"] = j2;
//    //dodać teraz w friendsFile to do pozycji [userID] items = s
    std::ofstream f(Config::friendsJSONPath);
    if(f.is_open())
    {
        f<<friendsFile;
    }
    else
    {
        throw std::runtime_error("Could not open file");
    }
}

