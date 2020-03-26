#ifndef LOGINDATA_H
#define LOGINDATA_H

#include "IValidator.h"
#include <string>

using std::string;

/*
 * Class which store data needed to log into the app
 */
class LogInData : public IValidator
{
private:
    string login;
    string password;

    //Non empty character, letters and numbers only
    static const std::regex loginReg;
    //Minimum eight characters, at least one uppercase letter, one lowercase letter and one number
    static const std::regex passwordReg;

public:
    LogInData(string p_login, string p_password);
    LogInData(const LogInData& data);
    ~LogInData() override;

    string GetLogin() const;
    void SetLogin(const string &value);
    string GetPassword() const;
    void SetPassword(const string &value);

    bool IsValid() override;
    bool operator==(const LogInData& data) const;

};

#endif // LOGINDATA_H
