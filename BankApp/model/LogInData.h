#ifndef LOGINDATA_H
#define LOGINDATA_H

#include "IValidator.h"
#include <string>
#include <iostream>

using std::string;

/*
 * Class which store data needed to log into the app
 */
class LogInData : public IValidator
{
protected:
    int id;
    string login;
    string password;
    string email;

private:
    //Non empty character, letters and numbers only
    static const std::regex loginReg;
    //Minimum eight characters, at least one uppercase letter, one lowercase letter and one number/special character
    static const std::regex passwordReg;
    //RFC 5322 Standard
    static const std::regex emailReg;

public:
    LogInData();
    LogInData(int p_id, string p_login, string p_password, string p_email);
    LogInData(string p_login, string p_password, string p_email);
    LogInData(const LogInData& data);
    ~LogInData() override;

    //GETTERS AND SETTERS---------------------
    int GetID() const;
    void SetID(int value);
    string GetLogin() const;
    void SetLogin(const string &value);
    string GetPassword() const;
    void SetPassword(const string &value);
    string GetEmail() const;
    void SetEmail(const string &value);
    //---------------------------------------

    bool IsValid() override;
    bool operator==(const LogInData& data) const;
    bool operator<(const LogInData& data) const;
    bool operator>(const LogInData& data) const;
    friend std::ostream &operator<<(std::ostream &output, const LogInData &data);

};

#endif // LOGINDATA_H
