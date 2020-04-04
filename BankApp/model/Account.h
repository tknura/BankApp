#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <list>
#include <iostream>

#include "History.h"
#include "Card.h"
#include "IAccount.h"


class Account// public IAccount
{
private:
    std::string number;
    double balance;
    std::list<int> memberIDlist;
 //   History history;
    std::list<Card> cardList;
public:
    //CONSTRUCTORS
//    Account()
//        :number(""), balance(0), memberIDlist(0)
//    {
//        history = {};
//        cardList = {};
//    }
    Account(std::string p_number, double p_balance, std::list<int> &p_memberIDlist, std::list<Card> & p_cardList)
        :number(p_number), balance(p_balance), memberIDlist(p_memberIDlist), cardList(p_cardList){std::cerr<<"utworzono obiekt account\n";}
//    Account(const Account&);
//    Account& operator=(const Account&);
//    Account(Account&&);
//    Account& operator=(Account&&);
//    ~Account();
//    //OTHER METHODS
//    void AddMember(int) override;
//    void UpdateHistory() override;
//    void UpdateBallance(int) override;
//    void AddCard(const Card &) override;
};

#endif // ACCOUNT_H
