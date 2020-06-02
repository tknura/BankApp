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
    QObject *dashboardTab;
    QObject *paymentsTab;
    QObject *fundsTab;
    QObject *historyTab;

public:
    void Initialize() override;
    void Connections() override;
    UserScreenController(QQmlApplicationEngine* p_engine);
    ~UserScreenController() override {}
};

#endif // USERSCREENCONTROLLER_H
