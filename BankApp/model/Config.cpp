#include "Config.h"

#include <fstream>
#include <regex>
#include <string>
#include <stdexcept>
#include <iostream>

#include <QString>
#include <QDir>
#include <QFile>
#include <QStandardPaths>

using reg = std::regex;

str Config::accountJSONPath = "";
str Config::fundJSONPath = "";
str Config::friendsJSONPath = "";
str Config::logInDataPath = "";

void Config::Initialize()
{
    auto path = QStandardPaths::writableLocation(QStandardPaths::HomeLocation);//ścieżka do ~/ , :C/Users/<user>
    std::string fullPath = path.toStdString() + "/BankApp/";

    QDir testDir(path+"/BankApp");
    if(!testDir.exists())//Sprawdzan czy istnieje folder .BankApp, jeżeli nie to go tworzy
    {
        if(QDir(path).mkdir("BankApp"))
        {
            std::cerr<<"Directory created succesfully\n";
        }
    }

    reg account("account:.+");//Wzorce regex
    reg fund("funds:.+");
    reg friends("friends:.+");
    reg logIn("login:.+");


    std::ifstream fin(fullPath + "config.txt");//próba otwarcia pliku  //trzeba zrobić tak, żeby otwierało config.txt z resourcefiles
    if(fin.is_open())
    {
        std::cerr<<"config.txt opend succesfully\n";
        std::string line;

        while(std::getline(fin, line))//Inicjalizuje składowe obiektu pełnymi ścieżkami
        {
            if(std::regex_search(line, account))
            {
                accountJSONPath = fullPath + line.substr(8,line.length());
                std::cerr<<accountJSONPath<<'\n';

            }
            else if(std::regex_search(line, fund))
            {
                fundJSONPath = fullPath + line.substr(6,line.length());
                std::cerr<<fundJSONPath<<'\n';

            }
            else if(std::regex_search(line, friends))
            {
                friendsJSONPath = fullPath + line.substr(8,line.length());
                std::cerr<<friendsJSONPath<<'\n';
            }
            else if(std::regex_search(line, logIn))
            {
                logInDataPath = fullPath + line.substr(6,line.length());
                std::cerr<<logInDataPath<<'\n';
            }
        }
        fin.close();
    }
    else
    {
        throw std::runtime_error("Could not open the config.txt file");
    }
}
