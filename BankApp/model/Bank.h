#ifndef BANK_H
#define BANK_H

#include "User.h"
#include "Admin.h"
#include "Config.h"
#include "Fund.h"
#include <iostream>
#include <map>
#include <list>
#include <random>
#include <memory>

using std::map;
using std::list;

class Bank
{
public://wydaje mi się, że wszystkie mapy i listy powinny być private
    static list<std::string> accountNumList;
    static list<std::string> fundNumList;

    static map<int, Fund> fundMap;
    //static map<std::string, Account> accountMap;
    static std::unordered_map<std::string,std::shared_ptr<Account>> accountMap;
    static map<std::string, Card> cardMap;

    static std::shared_ptr<IUser> currentlyLoggedUser;

    //variables used for generating random numbers
    static std::random_device rd;
    static std::mt19937 mt;

    static bool isAdminLogged();
    static bool isUserLogged();
    static void LogIn(std::shared_ptr<IUser> data);
    static void LogOut();
    static void Start();
    static void Stop();

    //search, update, getter methods for bank
    static bool UpdateOutputAccount(std::string &p_accNum, double p_amount);//Checks whether the funds are sufficinet if so updateds the balance. Throws and exceptions in case insufficient of funds.
    static void UpdateInputAccount(std::string &p_accNum, double p_amount);


};

#endif // BANK_H
