#include "Admin.h"

int Admin::currentId = 0;

Admin::Admin(const LogInData &data) : LogInData(data) {}

Admin::~Admin() {}

bool Admin::IsValid() {}

//void Admin::CreateUser(LogInData &data, std::string email) {

//}
