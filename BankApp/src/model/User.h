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
private:
    int id;
    string email;
    list<string> accountList;
    list<PaymentRetriever> friendsList;
    list<string> fundList;

public:
    User(int p_id);
    ~User();
    void MakePayment();
    void AddFriend(PaymentRetriever);
};

#endif // USER_H
