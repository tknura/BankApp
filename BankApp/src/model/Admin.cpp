#include "Admin.h"

int Admin::currentId = 0;

Admin::Admin(const LogInData &data) : LogInData(data) {}

Admin::~Admin() {}

void Admin::OnLogIn() {
}

bool Admin::IsValid() {
    return LogInData::IsValid();
}

//void Admin::CreateUser(LogInData &data, std::string email) {

//}
