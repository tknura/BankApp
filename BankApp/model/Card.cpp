#include "Card.h"

std::string Card::GetAccountNumber() const
{
    return accountNumber;
}

void Card::SetAccountNumber(const std::string &value)
{
    accountNumber = value;
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

