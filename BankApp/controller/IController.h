#ifndef ICONTROLLER_H
#define ICONTROLLER_H
#include <QQmlApplicationEngine>

class IController
{
public:
    virtual void Initialize(QQmlApplicationEngine* p_engine) = 0;
    virtual ~IController() {}
};

#endif // ICONTROLLER_H
