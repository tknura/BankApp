#ifndef IVALIDATOR_H
#define IVALIDATOR_H

#endif // IVALIDATOR_H

class IValidator {
public:
    IValidator() {}
    virtual ~IValidator() {}
    virtual bool IsValid() = 0;
};
