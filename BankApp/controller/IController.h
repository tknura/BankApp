#ifndef ICONTROLLER_H
#define ICONTROLLER_H
#include <QQmlApplicationEngine>

class IController
{
public:
    virtual void Initialize() = 0;
    virtual void Connections() = 0;
    virtual ~IController() {}
};

#endif // ICONTROLLER_H
