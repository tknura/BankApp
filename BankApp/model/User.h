#ifndef USER_H
#define USER_H

#include "PaymentRetriever.h"
#include "Payment.h"
#include "IUser.h"
#include "LogInData.h"
#include <list>
#include <string>

using std::list;
using std::string;

/*
 * Class which about the user
 */
class User : public IUser, public LogInData
{
private:
    list<string> accountList;
    //list<PaymentRetriever> friendsList;
    std::list<std::shared_ptr<PaymentRetriever>> friendsList;
    //list<string> fundList;

public:
    User(const LogInData& data);
    ~User() override;
    list<string>* GetAccountList(){return &accountList;}
    /*
     Metoda zakłada, że w gui upewniono się, że przelew miedzy danymi kontami jest dozwolony.
     Metoda nierozróznia przelewu własnego od normalnego.
     */
    void MakePayment(str& p_OutAccNum, double p_amount, str& p_title, str& p_date, str& p_name, str& p_InAccNum, str& p_address);//Throws an exepction when funds are insufficient
    void AddFriend(PaymentRetriever);
    void OnLogIn() override;
    void OnLogOut() override;
};

#endif // USER_H
