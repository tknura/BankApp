#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H

#include "Bank.h"
#include "Admin.h"
#include "User.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>

class Authorization
{
private:
    static bool VerifyUser(const LogInData &data);
public:
    static bool LogInAttempt(const LogInData &data);
    static LogInData proccesedData(const std::string &line);
};

#endif // AUTHORIZATION_H
