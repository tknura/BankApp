#include "JsonManager.h"
#include "Config.h"
#include "SavingsFund.h"
#include "RetirementFund.h"
#include "ChildAccount.h"
#include "SavingsAccount.h"
#include "FamillyAccount.h"
#include "CreditCard.h"
#include "DebitCard.h"

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

        Account * p {nullptr};

        for(const auto& account: accountFile[0]["accounts"])
        {
            using str = std::string;


            str type {account["type"]};
            str number {account["number"]};
            int supervisorId {account["supervisorId"]};
            double balance  {account["balance"]};
            if(type == "personal")
            {
                p = new Account{number,balance,supervisorId};
            }
            else if(type == "child")
            {
                int childId {account["childId"]};
                double dailyTransactionLimit {account["dailyTransactionLimit"]};
                p = new ChildAccount{number,balance,supervisorId,dailyTransactionLimit,childId};
            }
            else if(type == "savings")
            {

                double interest {account["interest"]};
                p = new SavingsAccount{number,balance,supervisorId,interest};
                p_accountMap.insert({number,p});
            }
            else if(type == "familly")
            {
                std::list<int> memberIdList {};
                for(const auto & id :account["memberIdList"])
                {
                    memberIdList.push_back((int)id);
                }
                p = new FamillyAccount{number,balance,supervisorId,memberIdList};
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

    if(f.is_open())
    {
        f>>cardFile;
        f.close();

        Card* p {nullptr};

        for(const auto& card :cardFile[0]["cards"])
        {
            str type {card["type"]};
            str accNumber {card["accNumber"]};
            str number {card["number"]};
            int ccv {card["ccv"]};
            double transactionLimit {card["transactionLimit"]};

            if(type == "prePaid")
            {
                p = new Card{accNumber,number,ccv,transactionLimit};
            }
            else if(type == "credit")
            {
                double maxCredit {card["maxCredit"]};
                str billingDate {card["billingDate"]};
                p = new CreditCard{accNumber,number,ccv,transactionLimit,maxCredit,billingDate};
            }
            else if(type == "debit")
            {
                double maxDebit {card["maxDebt"]};
                p = new DebitCard{accNumber,number,ccv,transactionLimit,maxDebit};
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

        Fund* p {nullptr};

        for(const auto & fund:fundsFile[0]["fundsList"])
        {
            using str = std::string;
            str type {fund["type"]};
            double minAmount {fund["minAmount"]};
            double maxRate {fund["maxRate"]};
            double fee {fund["fee"]};
            double balance {fund["balance"]};
            if(type == "retirement")
            {
                bool isRetired {fund["isRetired"]};
                double monthlyTransferIn {fund["monthlyTransferIn"]};
                p = new RetirementFund {minAmount,maxRate,fee,balance,isRetired,monthlyTransferIn};
            }
            else if(type == "savings")
            {
                str startDate {fund["startDate"]};
                str endDate {fund["endDate"]};
                p = new SavingsFund {minAmount,maxRate,fee,balance,startDate,endDate};
            }
            p_map.insert({fund["ownerID"],p});
        }
    }
    else
    {
        throw std::runtime_error("Could not open the fundData.json file");
    }
}
