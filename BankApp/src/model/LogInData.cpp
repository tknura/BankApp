#include "LogInData.h"

LogInData::LogInData(std::string p_login, std::string p_password) : login(p_login), password(p_password) {

}

LogInData::~LogInData(){}

bool LogInData::IsValid() {
    if(login.length() != 0 ){
        return true;
    }
    return  false;
}
