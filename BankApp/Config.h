#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <fstream>

using str = std::string;

//Klasa odpowiedzialna za otwarcie pliku config.txt i ustawienie wszystkich nazw plików

class Config
{
private:
    str accountJSONFileName;
    str fundJSONFileName;
    str friendsJSONFileName;
    str logInDataFileName;

public:
    Config();


};

#endif // CONFIG_H
