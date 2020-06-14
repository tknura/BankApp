#include <algorithm>

#include "User.h"
#include "Bank.h"
#include "JsonManager.h"


User::User(const LogInData &data) : LogInData(data) {
    friendsList = std::list<std::shared_ptr<PaymentRetriever>>{};
}

User::~User() {}

void User::LoadData()
{
    JsonManager manager(id);

     manager.ParseData(friendsList);
     manager.ParseData(accountList,Bank::accountMap);
     manager.ParseData(Bank::fundMap);
     manager.ParseData(Bank::cardMap);
}

void User::SaveData()
{
    JsonManager manager(id);
    manager.SerializeData(friendsList);
    manager.SerializeData(Bank::accountMap,Config::accountJSONPath);
    manager.SerializeData(Bank::fundMap,Config::fundJSONPath);
    manager.SerializeData(Bank::cardMap,Config::cardJSONPath);
}

void User::OnLogIn() {
    std::cerr << "User logged" << std::endl;
    LoadData();

}

void User::OnLogOut() {
    std::cerr << "User logged out" << std::endl;
    SaveData();



}

bool User::IsUserAccount(std::string &p_accNum)
{
    auto it = std::find(accountList.begin(),accountList.end(),p_accNum);
    if(it != accountList.end())
    {
        return true;//is present
    }
    else
    {
        return false;//is not present
    }

}
void User::MakePayment(str p_OutAccNum, double p_amount, str p_title, str p_date, str p_name, str p_InAccNum, str p_address)
{   
    bool isIncoming {!IsUserAccount(p_OutAccNum)};

    auto pPayment = std::make_shared<Payment>(-p_amount,p_title,p_date,p_name,p_InAccNum,p_address, isIncoming);
    if(Bank::UpdateOutputAccount(p_OutAccNum,pPayment))
    {
        auto pPayment = std::make_shared<Payment>(p_amount,p_title,p_date,p_name,"","", true);
        Bank::UpdateInputAccount(p_InAccNum,pPayment);

    }
    else
    {
        throw std::runtime_error("Insufficient funds");
    }
}

//User::~User() {}
