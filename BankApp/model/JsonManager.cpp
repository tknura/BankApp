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

listP JsonManager::ParseData()
{
    listP friends{};
    std::ifstream f(Config::friendsJSONPath);

    if(f.is_open())
    {
        f>>friendsFile;
        f.close();

        for (const auto& person: friendsFile[userID]["items"])//tu jest błąd powinno być friends data
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
void JsonManager::ParseData(listAcc& p_accountList, unorderedMapAcc& p_accountMap)
{
    std::ifstream f(Config::accountJSONPath);

    if(f.is_open())
    {
        f>>accountFile;
        f.close();

        std::shared_ptr<Account> p {nullptr};

        for(const auto& account: accountFile[0]["items"])
        {
            using str = std::string;


            int type {account["type"]};
            str number {account["number"]};
            int supervisorId {account["supervisorId"]};
            double balance  {account["balance"]};
            if(type == 0)
            {
                p = std::make_shared<Account>(number,balance,supervisorId);
            }
            else if(type == 2)
            {
                int childId {account["childId"]};
                double dailyTransactionLimit {account["dailyTransactionLimit"]};
                p = std::make_shared<ChildAccount>(number,balance,supervisorId,dailyTransactionLimit,childId);
            }
            else if(type == 1)
            {

                double interest {account["interest"]};
                p = std::make_shared<SavingsAccount>(number,balance,supervisorId,interest);
            }
            else if(type == 4)
            {
                std::list<int> memberIdList {};
                for(const auto & id :account["memberIdList"])
                {
                    memberIdList.push_back((int)id);
                }
                p = std::make_shared<FamillyAccount>(number,balance,supervisorId,memberIdList);
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
