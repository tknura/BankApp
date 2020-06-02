#include "LogInData.h"

const std::regex LogInData::loginReg = std::regex(".*");//work in progress
const std::regex LogInData::passwordReg = std::regex("(?=^.{8,}$)((?=.*\\d)|(?=.*\\W+))(?![.\n])(?=.*[A-Z])(?=.*[a-z]).*$");
const std::regex LogInData::emailReg = std::regex("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");

LogInData::LogInData()
    : id(-1), login(""), password(""), email("") {}

LogInData::LogInData(int p_id, std::string p_login, std::string p_password, std::string p_email)
    : id(p_id), login(p_login), password(p_password), email(p_email) {}

LogInData::LogInData(std::string p_login, std::string p_password, std::string p_email)
    : id(-1), login(p_login), password(p_password), email(p_email) {}

LogInData::LogInData(const LogInData &data)
    : id(data.GetID()), login(data.GetLogin()), password(data.GetPassword()), email(data.GetEmail()) {}

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
        && std::regex_match(email, emailReg)) {
        return true;
    }
    else {
        return false;
    }
}

bool LogInData::operator==(const LogInData &data) const {
    if(password == data.password && id == data.GetID()
        && login == data.login && email == data.email) {
        return true;
    }
    return false;
}

bool LogInData::operator<(const LogInData &data) const {
    return id < data.GetID();
}

bool LogInData::operator>(const LogInData &data) const {
    return id > data.GetID();
}

std::ostream& operator<<(std::ostream &output, const LogInData &data) {
    output  << data.GetID() << " " << data.GetLogin()
         << " " << data.GetPassword() << " " << data.GetEmail() << std::endl ;
    return output;
}
