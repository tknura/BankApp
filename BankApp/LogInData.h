#ifndef LOGINDATA_H
#define LOGINDATA_H

#include "IValidator.h"

class LogInData : public IValidator
{
public:
    LogInData();
    ~LogInData();
    bool IsValid() override;
};

#endif // LOGINDATA_H
