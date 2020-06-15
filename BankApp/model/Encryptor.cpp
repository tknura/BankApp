#include "Encryptor.h"

const std::string &Encryptor::encode(std::string &dataToHash, std::string &salt) {
    QCryptographicHash hash(QCryptographicHash::RealSha3_256);

    QRandomGenerator generator = QRandomGenerator::securelySeeded();
    salt = std::to_string(generator.generate64());

    std::string str = dataToHash + salt;
    hash.addData(str.c_str(), static_cast<int>(str.length()));
    dataToHash = hash.result().toHex().toStdString();

    return dataToHash;
}

const std::string Encryptor::constEncode(const std::string &dataToHash, const std::string &salt) {
    QCryptographicHash hash(QCryptographicHash::RealSha3_256);
    std::string tmp = dataToHash + salt;
    hash.addData(tmp.c_str(), static_cast<int>(tmp.length()));
    return hash.result().toHex().toStdString();
}
