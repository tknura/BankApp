#include "LogInData.h"

const std::regex LogInData::loginReg = std::regex("");
const std::regex LogInData::passwordReg = std::regex("");

LogInData::LogInData(std::string p_login, std::string p_password) : login(p_login), password(p_password) {}

LogInData::~LogInData() {}

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
