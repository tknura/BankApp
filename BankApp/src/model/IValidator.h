#ifndef IVALIDATOR_H
#define IVALIDATOR_H

#endif // IVALIDATOR_H

class IValidator {
public:
    virtual bool IsValid() = 0;
    virtual ~IValidator();
};
