#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H

#include "LogInData.h"

class Authorization
{
public:
    Authorization();
    bool VerifyUser(LogInData data);
    bool LogInAttempt(LogInData data);
};

#endif // AUTHORIZATION_H
