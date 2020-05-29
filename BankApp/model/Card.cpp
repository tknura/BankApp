#include "Card.h"
#include "Bank.h"

std::string Card::GetAccountNumber() const
{
    return accountNumber;
}

void Card::SetAccountNumber(const std::string &value)
{
    accountNumber = value;
}

std::string Card::GenerateNumber() {
    std::uniform_int_distribution<int> dist(0,9);
    std::string result;
    for(int i = 0; i <= 16; i++){
        char c = static_cast<char>(dist(Bank::mt)) + '0';
        result += c;
    }
    return result;
}

std::string Card::GenerateCCV() {
    std::uniform_int_distribution<int> dist(0,9);
    std::string result;
    for(int i = 0; i <= 2; i++){
        char c = static_cast<char>(dist(Bank::mt)) + '0';
        result += c;
    }
    return result;
}

json Card::SerializeToJson()
{
    json j{};
    
    j["accNumber"] = accountNumber;
    j["number"] = number;
    j["ccv"] = ccv;
    j["transactionLimit"] = transactionLimit;

    return j;
}

