#include "Bank.h"

list<std::string> Bank::accountNumList = list<std::string>();
list<std::string> Bank::fundNumList = list<std::string>();
//map<std::string, Account> Bank::accountMap = map<std::string, Account>();
std::unordered_map<std::string,std::shared_ptr<Account>> Bank::accountMap {};
map<int, Fund> Bank::fundMap = map<int, Fund>();
map<std::string, Card> Bank::cardMap = map<std::string, Card>();

std::shared_ptr<IUser> Bank::currentlyLoggedUser = nullptr;
std::random_device Bank::rd;
std::mt19937 Bank::mt = std::mt19937(rd());

/*
 * Method which create user object from passed data
 */
void Bank::LogIn(std::shared_ptr<IUser> data) {
    if(data){
        if((currentlyLoggedUser = std::dynamic_pointer_cast<Admin>(data))) {
            currentlyLoggedUser->OnLogIn();
        }
        else if((currentlyLoggedUser = std::dynamic_pointer_cast<User>(data))) {
            currentlyLoggedUser->OnLogIn();
        }
    }
}

void Bank::LogOut() {
    currentlyLoggedUser->OnLogOut();
}


/*
 * Method which is executed when the app starts
 */
void Bank::Start() {
    try {
        Config::Initialize();
    } catch (std::exception &ex) {
        std::cerr << ex.what() << std::endl;
    }
}

void Bank::Stop() {
    LogOut();
}

bool Bank::isAdminLogged() {
    if(std::dynamic_pointer_cast<Admin>(currentlyLoggedUser)) {
        return true;
    }
    else {
        return false;
    }
}

bool Bank::isUserLogged() {
    if(std::dynamic_pointer_cast<User>(currentlyLoggedUser)) {
        return true;
    }
    else {
        return false;
    }
}
bool Bank::UpdateOutputAccount(std::string &p_accNum,double p_amount)
{
    auto accountBalance = accountMap[p_accNum]->GetBalance();
    if(accountBalance >=p_amount)
    {
        accountMap[p_accNum]->SetBalance(accountBalance-p_amount);
        return true;
    }
    else
    {
        return false;
    }
}
void Bank::UpdateInputAccount(std::string &p_accNum, double p_amount)
{
    if(accountMap[p_accNum])//transfer to an account in the same bank
    {
        accountMap[p_accNum]->AddFunds(p_amount);
        std::cerr<<"internal transfer";
    }
    else//transfer to an account located in diffrent bank
    {
        std::cerr<<"external transfer";
    }


}
