#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include <fstream>

using str = std::string;

//Klasa odpowiedzialna za otwarcie pliku config.txt i ustawienie wszystkich nazw plików

class Config
{
public:
    static str accountJSONPath;
    static str fundJSONPath;
    static str friendsJSONPath;
    static str cardJSONPath;

    static str logInDataPath;
    static void Initialize();
};

#endif // CONFIG_H
