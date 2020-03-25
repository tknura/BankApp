#include "Bank.h"

IUser* Bank::currentlyLoggedUser = nullptr;

void Bank::LogIn(const LogInData &data) {
    std::cerr << "User logged" << std::endl;
}

void Bank::Start() {
    try {
        Config::Initialize();
    } catch (std::exception &ex) {
        std::cerr << ex.what() << std::endl;
    }
}
