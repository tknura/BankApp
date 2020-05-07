#include "User.h"
#include "Bank.h"

User::User(const LogInData &data) : LogInData(data) {}

User::~User() {}

void User::OnLogIn() {
    std::cerr << "User logged" << std::endl;
}

void User::OnLogOut() {

}
void User::MakePayment(string p_accNum, Payment &p_payment)
{
    auto amount = p_payment.GetAmount();
    if(Bank::UpdateOutputAccount(p_accNum,amount))
    {
        auto accNumber = p_payment.GetAccNumber();
        Bank::UpdateInputAccount(accNumber,amount);
    }
    else
    {
        throw std::runtime_error("Insufficient funds");
    }
}

//User::~User() {}
