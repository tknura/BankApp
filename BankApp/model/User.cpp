#include "User.h"
#include "Bank.h"
#include "JsonManager.h"


User::User(const LogInData &data) : LogInData(data) {}

User::~User() {}

void User::OnLogIn() {
    std::cerr << "User logged" << std::endl;
    //loading data from json to maps and lists
    JsonManager manager(id);
    //manager.ParseData(friendsList);// Nie działa, nie wiem dlaczego. Gdy wywołuje w main działa poprawnie.
    manager.ParseData(accountList,Bank::accountMap);
    manager.ParseData(Bank::fundMap);
    manager.ParseData(Bank::cardMap);
}

void User::OnLogOut() {
    //saving data from maps nad lists
    JsonManager manager(id);
//    manager.SerializeData(friendsList);
    manager.SerializeData(Bank::accountMap,Config::accountJSONPath);
    manager.SerializeData(Bank::fundMap,Config::fundJSONPath);
    manager.SerializeData(Bank::cardMap,Config::cardJSONPath);


}
void User::MakePayment(str& p_OutAccNum, double p_amount, str& p_title, str& p_date, str& p_name, str& p_InAccNum, str& p_address)
{
    auto pPayment = std::make_shared<Payment>(p_amount,p_title,p_date,p_name,p_InAccNum,p_address);
    if(Bank::UpdateOutputAccount(p_OutAccNum,pPayment))
    {
        Bank::UpdateInputAccount(p_InAccNum,p_amount);

    }
    else
    {
        throw std::runtime_error("Insufficient funds");
    }
}

//User::~User() {}
