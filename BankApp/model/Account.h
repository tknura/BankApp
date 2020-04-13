#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <list>
#include <iostream>
#include <random>

#include "History.h"
#include "Card.h"
#include "IAccount.h"
#include "json.hpp"

using json = nlohmann::json;

class Account// public IAccount
{
private:
    std::string number;
    double balance;
    int supervisorId;
    std::string type;
 //   History history;
  //  std::list<Card> cardList;
public:
    //CONSTRUCTORS
//    Account()
//        :number(""), balance(0), memberIDlist(0)
//    {
//        history = {};
//        cardList = {};
//    }

    Account(std::string p_number, double p_balance, int p_supervisorId,std::string p_type);
    Account(std::string p_number, int p_supervisorId);
    Account(int p_supervisorId);
    static std::string GenerateNumber();

//    Account(const Account&);
//    Account& operator=(const Account&);
//    Account(Account&&);
//    Account& operator=(Account&&);
//    //OTHER METHODS
//    void AddMember(int) override;
//    void UpdateHistory() override;
//    void UpdateBallance(int) override;
//    void AddCard(const Card &) override;
    std::string GetNumber() const;
    void SetNumber(const std::string &value);
    double GetBalance() const;
    void SetBalance(double value);
    int GetSupervisorId() const;
    void SetSupervisorId(int value);
    virtual json SerializeToJson();
};

#endif // ACCOUNT_H
