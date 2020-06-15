#ifndef STRINGPARSER_H
#define STRINGPARSER_H
#include <string>

class StringParser
{
public:
    static int GetIDFromUserString(std::string str);
    static double GetPercentageFromString(std::string str);
    static double GetMoneyFromString(std::string str);
};

#endif // STRINGPARSER_H
