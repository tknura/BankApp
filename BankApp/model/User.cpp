#include "User.h"

User::User(const LogInData &data) : LogInData(data) {}

User::~User() {}

void User::OnLogIn() {
    std::cerr << "User logged" << std::endl;
}

void User::OnLogOut() {

}

//User::~User() {}
