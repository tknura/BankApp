#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H

#include "LogInData.h"

class Authorization
{
public:
    Authorization();
    bool VerifyUser(LogInData);
    bool LogInAttempt(LogInData);
};

#endif // AUTHORIZATION_H
