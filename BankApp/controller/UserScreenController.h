#ifndef USERSCREENCONTROLLER_H
#define USERSCREENCONTROLLER_H

#include <QObject>
#include "IController.h"
#include "model/Admin.h"

class UserScreenController : QObject, IController
{
    Q_OBJECT

private:
    QObject *rootObject;

public:
    void Initialize(QQmlApplicationEngine* p_engine) override;
    UserScreenController(QQmlApplicationEngine* p_engine);
    ~UserScreenController() override {}

public slots:

};

#endif // USERSCREENCONTROLLER_H
