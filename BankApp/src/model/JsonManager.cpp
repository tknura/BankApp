#include "JsonManager.h"
#include "Config.h"
#include <fstream>

listP JsonManager::ParseFriendsData()
{
    listP friends;
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
