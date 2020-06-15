#include "StringParser.h"
#include <regex>

int StringParser::GetIDFromUserString(std::string str) {
    std::regex reg("\\d+");
    std::smatch sm;
    std::regex_search(str, sm, reg);
    return(std::stoi(sm[0].str()));
}

double StringParser::GetPercentageFromString(std::string str) {
    std::regex reg("\\d+(?:\\.\\d+)?");
    std::smatch sm;
    std::regex_search(str, sm, reg);
    return(std::stod(sm[0].str()));
}

double StringParser::GetMoneyFromString(std::string str) {
    std::regex reg("([+-]?[0-9]+(\\.[0-9]{2})?)");
    std::smatch sm;
    std::regex_search(str, sm, reg);
    return(std::stod(sm[0].str()));
}
