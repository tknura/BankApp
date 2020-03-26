#include "LogInData.h"

const std::regex LogInData::loginReg = std::regex("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)[a-zA-Z\\d]{8,}$");
const std::regex LogInData::passwordReg = std::regex("^[a-zA-Z0-9]+$");

LogInData::LogInData(const LogInData &data) : login(data.GetLogin()), password(data.GetPassword()) {}

LogInData::~LogInData() {}

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


bool LogInData::IsValid() {
    if (!std::regex_match(login, loginReg) && !std::regex_match(password, passwordReg)){
        return false;
    }
    return true;
}

bool LogInData::operator==(const LogInData &data) const {
    if(password == data.password && login == data.login){
        return true;
    }
    return false;
}
