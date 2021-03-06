#include "Account.h"
#include "Bank.h"


Account::Account(History p_history, std::string p_number, double p_balance, int p_supervisorId)
    :number(p_number), balance(p_balance), supervisorId(p_supervisorId), history(p_history)
{
    std::cerr<<"Account object created\n";
}

Account::Account(std::string p_number, double p_balance, int p_supervisorId)
    :number(p_number), balance(p_balance), supervisorId(p_supervisorId)
{
    std::cerr<<"Account object created\n";
}

Account::Account(std::string p_number, int p_supervisorId)
    : number(p_number), balance(0), supervisorId(p_supervisorId) {}

Account::Account(int p_supervisorId)
    :number(GenerateNumber()) , balance(0), supervisorId(p_supervisorId) {}

std::string Account::GenerateNumber() {
    std::uniform_int_distribution<int> dist(0,9);
    std::string result;
    for(int i = 0; i <= 16; i++){
                char c = static_cast<char>(dist(Bank::mt)) + '0';
                result += c;
    }
    return result;
}

std::string Account::GetNumber() const
{
    return number;
}

void Account::SetNumber(const std::string &value)
{
    number = value;
}

double Account::GetBalance() const
{
    return balance;
}

void Account::SetBalance(double value)
{
    balance = value;
}


void Account::SetSupervisorId(int value)
{
    supervisorId = value;
}
void Account::UpdateHistory(std::shared_ptr<Payment> p_payment)
{
    //std::cerr<<"info o historii"<<p_payment->GetName().toStdString()<<" "<<p_payment->GetAmount();
    history.AddNode(p_payment);
}
json Account::SerializeToJson()
{
    json j{};
    j["history"] = history.SerializeToJson();
    j["number"] = number;
    j["supervisorId"] = supervisorId;
    j["balance"] = balance;

    return j;
}
