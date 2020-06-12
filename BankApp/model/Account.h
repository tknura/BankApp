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

class Account: public IAccount
{
private:
    std::string number;
    double balance;
    int supervisorId;
    History history;
public:
    Account(History p_history, std::string p_number, double p_balance, int p_supervisorId);
    Account(std::string p_number, double p_balance, int p_supervisorId);
    Account(std::string p_number, int p_supervisorId);
    Account(int p_supervisorId);
    static std::string GenerateNumber();

    virtual History* GetHistory() override {return &history;}


    virtual void UpdateHistory(std::shared_ptr<Payment> p_payment)override;
    std::string GetNumber() const;
    void SetNumber(const std::string &value);
    virtual double GetBalance() const override;
    virtual void SetBalance(double value) override;
    int GetSupervisorId() const;
    void SetSupervisorId(int value);
    virtual void AddFunds(double p_amount)override{balance+=p_amount;}
    virtual json SerializeToJson() override;

    virtual int GetType()override{return 0;}
};

#endif // ACCOUNT_H
