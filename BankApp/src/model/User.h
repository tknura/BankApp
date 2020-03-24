#ifndef USER_H
#define USER_H

#include "PaymentRetriever.h"
#include "IUser.h"
#include "LogInData.h"
#include <list>
#include <string>

using std::list;
using std::string;

class User : public IUser, public LogInData
{
public:
    User();
    ~User();
    void MakePayment();
    void AddFriend(PaymentRetriever);

private:
    int id;
    list<string> accountList;
    list<PaymentRetriever> friendsList;
    list<string> fundList;
};

#endif // USER_H
