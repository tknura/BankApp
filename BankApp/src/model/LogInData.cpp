#include "LogInData.h"

const std::regex LogInData::loginReg = std::regex("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)[a-zA-Z\\d]{8,}$");
const std::regex LogInData::passwordReg = std::regex("");
const std::regex LogInData::emailReg = std::regex("\\A[a-z0-9!#$%&'*+/=?^_‘{|}~-]+(?:\\.[a-z0-9!#$%&'*+/=?^_‘{|}~-]+)*@ (?:[a-z0-9](?:[a-z0-9-]*[a-z0-9])?\\.)+[a-z0-9](?:[a-z0-9-]*[a-z0-9])?\\z");

LogInData::LogInData(int p_id, std::string p_login, std::string p_password, std::string p_email)
    : id(p_id), login(p_login), password(p_password), email(p_email) {}

LogInData::LogInData(const LogInData &data)
    : id(data.GetID()), login(data.GetLogin()), password(data.GetPassword()) {}

LogInData::~LogInData() {}
int LogInData::GetID() const {
    return id;
}

//GETTERS AND SETTERS------------------------------------------------------
void LogInData::SetID(int value) {
    id = value;
}

string LogInData::GetLogin() const
{
    return login;
}

void LogInData::SetLogin(const string &value)
{
    login = value;
}

string LogInData::GetPassword() const
{
    return password;
}

void LogInData::SetPassword(const string &value)
{
    password = value;
}

string LogInData::GetEmail() const {
    return email;
}

void LogInData::SetEmail(const string &value) {
    email = value;
}
//------------------------------------------------------------------------

bool LogInData::IsValid() {
    if (id >= 0
        && std::regex_match(login, loginReg)
        && std::regex_match(password, passwordReg)
        && std::regex_match(email, emailReg)){
        return true;
    }
    return false;
}

bool LogInData::operator==(const LogInData &data) const {
    if(password == data.password && id == data.GetID()
        && login == data.login && email == data.email){
        return true;
    }
    return false;
}
