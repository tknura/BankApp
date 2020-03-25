#include "Authorization.h"

//TODO get LogInData.txt filename from Config class
bool Authorization::VerifyUser(const LogInData &data) {
    std::fstream file;
    file.open("LogInData.txt", std::ios::in);
    if(file.is_open()){
        file.exceptions( std::fstream::badbit );
        try {
            std::string line;
            while(std::getline(file, line)){
                if(proccesedData(line) == data){
                    return true;
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
    return false;
}

bool Authorization::LogInAttempt(const LogInData &data) {
    if(VerifyUser(data)){
        Bank::LogIn(data);
        return true;
    }
    else {
        return false;
    }
}

LogInData Authorization::proccesedData(const std::string &line) {
    std::istringstream iss(line);
    std::vector<std::string> tokens;
    std::copy(std::istream_iterator<string>(iss), std::istream_iterator<string>(),
              std::back_inserter(tokens));
    LogInData result(tokens[1], tokens[2]);
    return result;
}
