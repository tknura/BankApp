#ifndef ADMIN_H
#define ADMIN_H

#include "LogInData.h"
#include "enums/AccountType.h"
#include "enums/CardType.h"
#include "enums/FundType.h"
#include "Authorization.h"
#include <fstream>

using std::map;

class Admin : public IUser, public LogInData
{
private:
    static int idProvider;
    static map<int, LogInData> usersMap;
    void FillUserMap();
    void SaveUserMap();
    bool FindExistingUser(LogInData& data);
    bool AddAccountToMap(std::shared_ptr<Account> acc);
    bool AddCardToMap(std::shared_ptr<Card> card);
    bool AddFundToMap(std::shared_ptr<Fund> fund);
public:
    Admin(const LogInData &data);
    ~Admin() override;
    bool CreateUser(string p_login, string p_password, string p_email);
    bool CreateAccount(int ownerID, string number, double balance);
    bool CreateAccount(int supervisorID, int childID, std::string number, double balance,
                    double dailyTransactionLimit);
    bool CreateAccount(int supervisorID, std::string number, double balance, std::list<int> memberIdList);
    bool CreateAccount(int ownerID, std::string number, double balance, double interest);

    bool AddCard(std::string accountNumber, std::string number, int ccv, double transactionLimit);
    bool AddCard(std::string accountNumber, std::string number, int ccv, double transactionLimit,
                 double maxCredit, std::string billingDate);
    bool AddCard(std::string accountNumber, std::string number, int ccv, double transactionLimit,
                 double maxDebt);

    bool AddFund(int ownerID, double minAmount, double maxRate, double fee, double balance);
    bool AddFund(int ownerID, double minAmount, double maxRate, double fee, double balance,
                 bool isRetired, double monthlyIn);
    bool AddFund(int ownerID, double minAmount, double maxRate, double fee, double balance,
                 std::string startDate, std::string endDate);

    void OnLogIn() override;
    void OnLogOut() override;
    static std::list<std::string> GetUsersStringList();
//    bool IsValid() override;
};

#endif // ADMIN_H
