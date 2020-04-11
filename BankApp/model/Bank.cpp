#include "Bank.h"

list<std::string> Bank::accountNumList = list<std::string>();
list<std::string> Bank::fundNumList = list<std::string>();
map<std::string, Account> Bank::accountMap = map<std::string, Account>();
map<std::string,Fund> Bank::fundMap = map<std::string, Fund>();

std::shared_ptr<IUser> Bank::currentlyLoggedUser = nullptr;
std::random_device Bank::rd;
std::mt19937 Bank::mt = std::mt19937(rd());
/*
 * Method which create user object from passed data
 */
void Bank::LogIn(std::shared_ptr<IUser> data) {
    if(data){
        if((currentlyLoggedUser = std::dynamic_pointer_cast<Admin>(data))) {
            currentlyLoggedUser->OnLogIn();
        }
        else if((currentlyLoggedUser = std::dynamic_pointer_cast<User>(data))) {
            currentlyLoggedUser->OnLogIn();
        }
    }
}

void Bank::LogOut() {
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

void Bank::Stop() {
}
