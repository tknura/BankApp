#ifndef LOGINDATA_H
#define LOGINDATA_H

#include "IValidator.h"
#include <string>

using std::string;

class LogInData : public IValidator
{
private:
    string login;
    string password;

public:
    LogInData(string p_login, string p_password);
    ~LogInData() override;
    bool IsValid() override;
};

#endif // LOGINDATA_H
