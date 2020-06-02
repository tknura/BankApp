#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include "LogInScreenController.h"
#include "IController.h"
#include <QObject>

class MainController : public QObject, IController
{
    Q_OBJECT

private:
    QObject *rootObject;
    QQmlApplicationEngine* engine;
    LogInScreenController* lsc;

public:
    MainController(QQmlApplicationEngine* p_engine);
    ~MainController() override;
    void Initialize() override;
    void Connections() override;
    QObject* GetRootObject();
};

#endif // MAINCONTROLLER_H
