#include "Account.h"
#include "Bank.h"

//Account::Account(const Account&)
//{

//}
//Account& Account::operator=(const Account&)
//{

//}
//Account::Account(Account&&)
//{

//}
//Account& Account::operator=(Account&&)
//{

//}
//Account::~Account()
//{

//}

Account::Account(std::string p_number, double p_balance, int p_supervisorId,std::string p_type)
    :number(p_number), balance(p_balance), supervisorId(p_supervisorId), type(p_type)
{
    std::cerr<<"utworzono obiekt account\n";
}
Account::Account(std::string p_number, double p_balance, int p_supervisorId)
    :number(p_number), balance(p_balance), supervisorId(p_supervisorId)
{
    std::cerr<<"utworzono obiekt account\n";
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

int Account::GetSupervisorId() const
{
    return supervisorId;
}

void Account::SetSupervisorId(int value)
{
    supervisorId = value;
}

json Account::SerializeToJson()
{
    json j{};

    j["type"] = type;
    j["number"] = number;
    j["supervisorId"] = supervisorId;
    j["balance"] = balance;

    return j;
}
