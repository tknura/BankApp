#ifndef LOGINDATA_H
#define LOGINDATA_H

#include "IValidator.h"
#include <string>
#include "InvalidLoginException.h"


using std::string;

class LogInData : public IValidator
{
private:
    string login;
    string password;

    static const std::regex loginReg;
    static const std::regex passwordReg;

public:
    LogInData(string p_login, string p_password);
    ~LogInData() override;
    bool IsValid() override;
    bool operator==(const LogInData& data) const;
};

#endif // LOGINDATA_H
