#include "JsonManager.h"
#include "Config.h"
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
listAcc JsonManager::ParseAccountData()
{
    listAcc accounts{};
    std::list<int> ownerIDlist{};
    std::list<Card> cardList{};
    std::cerr<<Config::accountJSONPath;
    std::ifstream f(Config::accountJSONPath);

    if(f.is_open())
    {
        f>>accountFile;
        f.close();

        for(const auto& account: accountFile[0]["lista"])//tutaj coś nie działa
        {
            using str = std::string;

            str type {account["type"]};
            str number {account["number"]};
            for(const auto& id: account["ownerID"])
            {
                ownerIDlist.push_back((int)id);
            }
            double balance  {account["balance"]};
            for(const auto& card: account["cards"])
            {
                str cardNum {card["number"]};
                int ccv {card["ccv"]};
                double transactionLimit {card["transactionLimit"]};
                Card m{number,ccv,transactionLimit};
                cardList.push_back(m);
            }
            Account m{number,balance,ownerIDlist,cardList};
            accounts.push_back(m);
        }
    }
    else
    {
        throw std::runtime_error("Could not open the accountsData.json file");
    }
    return accounts;
}
