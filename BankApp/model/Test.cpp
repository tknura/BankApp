#include "Test.h"
#include "LogInData.h"
#include "User.h"
#include "Bank.h"
#include "Payment.h"
#include "PaymentRetriever.h"

void Test::Run() {

    std::unordered_map<std::string,std::shared_ptr<Account>> test{};
    std::list<std::string> numery{};
    JsonManager p {1};
    p.ParseData(numery,test);
    p.SerializeData(test,Config::accountJSONPath);

}
