#ifndef IUSER_H
#define IUSER_H

/*
 * Application user interface
 */
class IUser
{
public:
    IUser() {}
    virtual ~IUser() {}
    virtual void OnLogIn() = 0;
};

#endif // IUSER_H
