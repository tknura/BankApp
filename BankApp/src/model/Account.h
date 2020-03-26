#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <list>

#include "History.h"
#include "Card.h"


class Account
{
private:
    std::string number;
    double balance;
    std::list<int> memberIDlist;
    History history;
    std::list<Card> cardList;
public:
    Account();
    ~Account();
};

#endif // ACCOUNT_H
