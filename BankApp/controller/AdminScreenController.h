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

    static std::shared_ptr<Admin> admin;
public slots:
    void HandleLogOutButton();
};

#endif // ADMINSCREENCONTROLLER_H
