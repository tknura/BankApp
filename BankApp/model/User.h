#ifndef USER_H
#define USER_H

#include "PaymentRetriever.h"
#include "Payment.h"
#include "IUser.h"
#include "LogInData.h"
#include <list>
#include <string>
#include "JsonManager.h"

using std::list;
using std::string;

/*
 * Class which about the user
 */
class User : public IUser, public LogInData
{
private:
    list<string> accountList;
    std::list<std::shared_ptr<PaymentRetriever>> friendsList;
    JsonManager manager;

public:
    User(const LogInData& data);
    ~User() override;
    list<string>* GetAccountList(){return &accountList;}
    std::list<std::shared_ptr<PaymentRetriever>>* GetFriendsList(){return &friendsList;}
    void LoadData();//creates JsonManager instance and invokes its ParseData methods
    void SaveData();//creates JsonManager instance and invokes its SerializeData methods

    bool MakePayment(str p_OutAccNum, double p_amount, str p_title, str p_date, str p_name, str p_InAccNum, str p_address);//Throws an exepction when funds are insufficient
    bool AddFriend(string p_name, string p_accNumber, string p_address);
    void OnLogIn() override;
    void OnLogOut() override;
    bool IsUserAccount(std::string& p_accNum);
};

#endif // USER_H
