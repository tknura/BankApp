#include "Bank.h"

IUser* Bank::currentlyLoggedUser = nullptr;

/*
 * Method which create user object from passed data
 */
void Bank::LogIn(IUser* data) {
    if(!data){
        currentlyLoggedUser = data;

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
