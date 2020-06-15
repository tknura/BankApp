#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H

#include "Bank.h"
#include "Admin.h"
#include "User.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <memory>
#include <tuple>

class Authorization
{
public:
    static bool VerifyUser(LogInData &data);
    static bool LogInAttempt(LogInData &data);
    static std::tuple<LogInData, std::string> proccesedData(const std::string &line);
};

#endif // AUTHORIZATION_H
