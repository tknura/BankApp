#ifndef USERSCREENCONTROLLER_H
#define USERSCREENCONTROLLER_H

#include <QObject>
#include "IController.h"
#include "PaymentTabController.h"
#include "model/Admin.h"

class UserScreenController : QObject, IController
{
    Q_OBJECT

private:
    PaymentTabController *pmntTabControler;
    QObject* rootObject;
public:
    void Initialize() override;
    void Connections() override;
    UserScreenController(QQmlApplicationEngine* p_engine);
    ~UserScreenController() override;
    static QStringList usrAccounts();
};

#endif // USERSCREENCONTROLLER_H
