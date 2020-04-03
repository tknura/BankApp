#include "Bank.h"

IUser* Bank::currentlyLoggedUser = nullptr;

/*
 * Method which create user object from passed data
 */
void Bank::LogIn(IUser* data) {
    if(data){
        if(dynamic_cast<Admin*>(data)) {
            currentlyLoggedUser = dynamic_cast<Admin*>(data);
            currentlyLoggedUser->OnLogIn();
        }
        else if(dynamic_cast<User*>(data)) {
            currentlyLoggedUser = dynamic_cast<User*>(data);
            currentlyLoggedUser->OnLogIn();
        }
    }
}

/*
 * Method which is executed when the app starts
 */
void Bank::Start() {
    try {
        Config::Initialize();
    } catch (std::exception &ex) {
        std::cerr << ex.what() << std::endl;
    }
}
