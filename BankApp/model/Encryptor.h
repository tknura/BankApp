#ifndef ENCRYPTOR_H
#define ENCRYPTOR_H

#include <QRandomGenerator>
#include <QDebug>
#include <QCryptographicHash>

#include <stdio.h>
#include <string.h>
#include <algorithm>

class Encryptor
{
public:
    static const std::string& encode(std::string& password, std::string& salt);
    static const std::string constEncode(const std::string& password, const std::string& salt);
};

#endif // ENCRYPTOR_H
