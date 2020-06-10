#ifndef IUSER_H
#define IUSER_H

#include <list>
#include <string>

/*
 * Application user interface
 */
class IUser
{
public:
    IUser() {}
    virtual ~IUser() {}
    virtual void OnLogIn() = 0;
    virtual void OnLogOut() = 0;
    //virtual std::list<std::string>* GetAccountList() = 0;
};

#endif // IUSER_H
