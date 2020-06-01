#include "User.h"
#include "Bank.h"


User::User(const LogInData &data) : LogInData(data) {}

User::~User() {}

void User::OnLogIn() {
    std::cerr << "User logged" << std::endl;
}

void User::OnLogOut() {

}
void User::MakePayment(str& p_OutAccNum, double p_amount, str& p_title, str& p_date, str& p_name, str& p_InAccNum, str& p_address)
{
    auto pPayment = std::make_shared<Payment>(p_amount,p_title,p_date,p_name,p_InAccNum,p_address);
    if(Bank::UpdateOutputAccount(p_OutAccNum,pPayment))//zmiana1
    {
        Bank::UpdateInputAccount(p_InAccNum,p_amount);

    }
    else
    {
        throw std::runtime_error("Insufficient funds");
    }
}

//User::~User() {}
