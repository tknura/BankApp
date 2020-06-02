#ifndef ADMINSCREENCONTROLLER_H
#define ADMINSCREENCONTROLLER_H

#include <QObject>
#include "IController.h"
#include "model/Admin.h"
#include "AccountAdditionController.h"
#include "CardAdditionController.h"
#include "UserAdditionController.h"
#include "FundAdditionController.h"

class AdminScreenController : QObject, IController
{
    Q_OBJECT

private:
    QObject *rootObject;
    UserAdditionController* usrAddTabController;
    AccountAdditionController* accAddTabController;
    CardAdditionController* cardAddTabController;
    FundAdditionController* fundAddTabController;

public:
    void Initialize() override;
    void Connections() override;
    AdminScreenController(QQmlApplicationEngine* p_engine);
    ~AdminScreenController() override;
    static QStringList UserList();
    static QStringList AccList();
    static int GetIDFromUserString(std::string str);
    static double GetPercentageFromString(std::string str);
    static double GetMoneyFromString(std::string str);

    static std::shared_ptr<Admin> admin;
};

#endif // ADMINSCREENCONTROLLER_H
