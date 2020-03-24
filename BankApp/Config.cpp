#include "Config.h"

#include <fstream>
#include <regex>
#include <string>
#include <stdexcept>

using reg = std::regex;

Config::Config()
{
    reg account("account:.+");
    reg fund("funds:.+");
    reg friends("friends:.+");
    reg logIn("login:.+");

    std::ifstream fin("~/Desktop/BankApp/BankApp/config.txt"); //na stałe wpisana nazwa pliku config
    fin.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    if(fin.is_open())
    {
        std::string line;
        std::smatch result;

        while(std::getline(fin, line))
        {
            if(std::regex_search(line, result, account))
            {
                accountJSONFileName = line;
            }
            else if(std::regex_search(line, result, fund))
            {
                fundJSONFileName = line;
            }
            else if(std::regex_search(line, result, friends))
            {
                friendsJSONFileName = line;
            }
            else if(std::regex_search(line, result, logIn))
            {
                logInDataFileName = line;
            }
        }
        fin.close();
    }
    else
    {
        //throw std::runtime_error("Could not open config.txt");
    }

}
