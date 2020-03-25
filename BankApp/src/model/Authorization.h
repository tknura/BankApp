#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H

#include "LogInData.h"
#include "Bank.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>

class Authorization
{
public:
    static bool VerifyUser(const LogInData &data);
    static bool LogInAttempt(const LogInData &data);
    static LogInData proccesedData(const std::string &line);
};

#endif // AUTHORIZATION_H
