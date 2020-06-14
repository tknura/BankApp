#ifndef BANK_H
#define BANK_H

#include "User.h"
#include "Admin.h"
#include "Config.h"
#include <iostream>
#include <map>
#include <list>
#include <random>
#include <memory>

using std::map;
using std::list;

class Bank
{
private:
    static std::shared_ptr<IUser> currentlyLoggedUser;

public:
    static list<std::string> accountNumList;
    static list<std::string> fundNumList;

    static std::multimap<int,std::shared_ptr<Fund>> fundMap;
    static std::unordered_map<std::string,std::shared_ptr<IAccount>> accountMap;
    static std::multimap<std::string,std::shared_ptr<Card>> cardMap;

    //variables used for generating random numbers
    static std::random_device rd;
    static std::mt19937 mt;

    static bool isAdminLogged();
    static bool isUserLogged();
    static void LogIn(std::shared_ptr<IUser> data);
    static void LogOut();
    static void Start();
    static void Stop();

    template <typename T>
    static std::shared_ptr<T> GetLoggedUser() {
        std::shared_ptr<T> user = std::dynamic_pointer_cast<T>(currentlyLoggedUser);
        if(user) {
            return user;
        }
        else {
            return nullptr;
        }
    }
    //search, update, getter methods for bank
    static bool UpdateOutputAccount(std::string &p_accNum, std::shared_ptr<Payment> p_payment);//Checks whether the funds are sufficinet if so updateds the balance. Throws and exceptions in case insufficient of funds.
    static void UpdateInputAccount(std::string &p_accNum, std::shared_ptr<Payment> p_payment);


};

#endif // BANK_H
