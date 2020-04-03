#include "Admin.h"

int Admin::idProvider = 0;

Admin::Admin(const LogInData &data) : LogInData(data) {}

Admin::~Admin() {}

bool Admin::CreateUser(std::string p_login, std::string p_password, std::string p_email) {

    LogInData data(idProvider++, p_login, p_password, p_email);
    if(data.IsValid()) {
        if(!Authorization::FindData(data)){
            User newUser(data);
            return SaveUser(newUser);
        }
        else{
            std::cerr << "User " << data.GetLogin() << " already exist" << std::endl;
            return false;
        }
    }
    else {
        return false;
    }
}

void Admin::OnLogIn() {
    std::cerr << "Admin logged" << std::endl;
}

//bool Admin::IsValid() {
//    return LogInData::IsValid();
//}

bool Admin::SaveUser(User& user) {
    std::fstream file;
    file.open(Config::logInDataPath, std::ios::out | std::ios::app);
    if(file.is_open()){
        file.exceptions( std::fstream::badbit );
        try {
            file  << user.GetID() << " " << user.GetLogin()
                 << " " << user.GetPassword() << " " << user.GetEmail() << std::endl ;
        }
        catch (std::fstream::failure & ex) {
            std::cerr << "Log in data parsing failure: "<< ex.what() << std::endl;
        }
    }
    else{
        std::cerr << "Could not open file with log in data" << std::endl;
    }
    file.close();
    return true;
}
