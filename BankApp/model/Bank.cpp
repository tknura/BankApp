#include "Bank.h"
#include "JsonManager.h"

list<std::string> Bank::accountNumList = list<std::string>();
list<std::string> Bank::fundNumList = list<std::string>();

std::unordered_map<std::string,std::shared_ptr<IAccount>> Bank::accountMap {};
std::multimap<int,std::shared_ptr<Fund>> Bank::fundMap {};
std::multimap<std::string,std::shared_ptr<Card>> Bank::cardMap {};

std::shared_ptr<IUser> Bank::currentlyLoggedUser = nullptr;
std::mt19937 Bank::mt = std::mt19937(time(0));

/*
 * Method which create user object from passed data
 */
void Bank::LogIn(std::shared_ptr<IUser> data) {
    if(data){
        currentlyLoggedUser = data;
        currentlyLoggedUser->OnLogIn();
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
bool Bank::UpdateOutputAccount(std::string &p_accNum,std::shared_ptr<Payment> p_payment)
{

    auto accountBalance = accountMap[p_accNum]->GetBalance();
    if(accountBalance >=-p_payment->GetAmount())
    {
        std::cerr<<"\namount to transfer"<<p_payment->GetAmount();
        accountMap[p_accNum]->SetBalance(accountBalance+p_payment->GetAmount());
        std::cerr<<"\nbalance after transfer"<<accountMap[p_accNum]->GetBalance();
        accountMap[p_accNum]->UpdateHistory(p_payment);
        return true;
    }
    else
    {
        return false;
    }
}
void Bank::UpdateInputAccount(std::string &p_accNum,std::shared_ptr<Payment> p_payment)
{
    //std::cerr<<"\nInput acc number:"<<p_accNum;
    if(accountMap[p_accNum])//transfer to an account in the same bank
    {
        accountMap[p_accNum]->AddFunds(p_payment->GetAmount());
        accountMap[p_accNum]->UpdateHistory(p_payment);
       // std::cerr<<"internal transfer";
    }
    else//transfer to an account located in diffrent bank
    {
        //std::cerr<<"external transfer w input";
    }


}
