#include "Admin.h"

int Admin::currentId = 0;

Admin::Admin(std::string p_login, std::string p_password) : LogInData(p_login, p_password) {}

Admin::Admin(const LogInData &data) : LogInData(data) {}

void Admin::CreateUser(LogInData &data, std::string email) {

}
