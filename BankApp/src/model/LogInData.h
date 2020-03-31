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
protected:
    int id;
    string login;
    string password;
    string email = "";

private:
    //Non empty character, letters and numbers only
    static const std::regex loginReg;
    //Minimum eight characters, at least one uppercase letter, one lowercase letter and one number
    static const std::regex passwordReg;
    //RFC 5322 Standard
    static const std::regex emailReg;

public:
    LogInData(int p_id, string p_login, string p_password);
    LogInData(int p_id, string p_login, string p_password, string p_email);
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

    virtual bool IsValid() override;
    bool operator==(const LogInData& data) const;

};

#endif // LOGINDATA_H
