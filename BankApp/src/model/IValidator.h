#ifndef IVALIDATOR_H
#define IVALIDATOR_H

#include <regex>

class IValidator {
public:
    IValidator() {}
    virtual ~IValidator() {}
    virtual bool IsValid() = 0;
};

#endif // IVALIDATOR_H
