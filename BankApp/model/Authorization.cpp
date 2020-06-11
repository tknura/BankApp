#include "Authorization.h"

/*
 * Method which return true if LogInData passed as an argument
 * match existing LogInData in proper file
 */
bool Authorization::VerifyUser(LogInData &data) {
    std::fstream file;
    file.open(Config::logInDataPath, std::ios::in);
    if(file.is_open()){
        file.exceptions( std::fstream::badbit );
        try {
            std::string line;
            while(std::getline(file, line)){
                LogInData logInDataFromLine = proccesedData(line);
                if(data.GetID() < 0) {
                    if(logInDataFromLine.GetPassword() == data.GetPassword() &&
                        (logInDataFromLine.GetEmail() == data.GetEmail()
                         || logInDataFromLine.GetLogin() == data.GetLogin())) {
                            data.SetID(logInDataFromLine.GetID());
                            file.close();
                            return true;
                    }
                }
            }
        }
        catch (std::fstream::failure & ex) {
            std::cerr << "Log in data parsing failure: "<< ex.what() << std::endl;
        }
    }
    else {
        std::cerr << "Could not open file with log in data" << std::endl;
    }
    file.close();
    return false;
}

/*
 * Method which call FindData and depending on its results call
 * LogIn function in Bank class
 */
bool Authorization::LogInAttempt(LogInData &data) {
    if(data.GetLogin() == "admin" && data.GetPassword() == "admin"){
        Bank::LogIn(std::make_shared<Admin>(data));
        return true;
    }
    else if(VerifyUser(data)){
        Bank::LogIn(std::make_shared<User>(data));
        return true;
    }
    else {
        return false;
    }
}

/*
 * Method which gets LogInData from passed string which is a line from
 * logInData file with following format:
 * <id> <login> <password> <email>
 */
LogInData Authorization::proccesedData(const std::string &line) {
    std::istringstream iss(line);
    std::vector<std::string> tokens;
    std::copy(std::istream_iterator<string>(iss), std::istream_iterator<string>(),
              std::back_inserter(tokens));
    if(tokens.size() == 4) {
        LogInData result(std::stoi(tokens[0]), tokens[1], tokens[2], tokens[3]);
        return result;
    }
    return LogInData();
}
