#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <fstream>

using str = std::string;

//Klasa odpowiedzialna za otwarcie pliku config.txt i ustawienie wszystkich nazw plików

class Config
{
private:
    str accountJSONPath;
    str fundJSONPath;
    str friendsJSONPath;
    str logInDataPath;

public:
    Config();


};

#endif // CONFIG_H
