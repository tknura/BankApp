#ifndef USER_H
#define USER_H

#include "PaymentRetriever.h"
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
    list<PaymentRetriever> friendsList;
    list<string> fundList;

public:
    User(const LogInData& data);
    ~User() override;
    void MakePayment();
    void AddFriend(PaymentRetriever);
    void OnLogIn() override;
};

#endif // USER_H
