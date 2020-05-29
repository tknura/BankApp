#include "AdminScreenController.h"

void AdminScreenController::Initialize(QQmlApplicationEngine *p_engine) {
    rootObject = p_engine->rootObjects().first()->findChild<QObject*>("adminScreen");
    usrAddTabController = new UserAdditionController(p_engine);
    accAddTabController = new AccountAdditionController(p_engine);
    cardAddTabController = new CardAdditionController(p_engine);
    fundAddTabController = new FundAdditionController(p_engine);
}

AdminScreenController::AdminScreenController(QQmlApplicationEngine *p_engine) {
    Initialize(p_engine);
}

AdminScreenController::~AdminScreenController() {
    delete usrAddTabController;
    delete accAddTabController;
    delete cardAddTabController;
    delete fundAddTabController;
}

QStringList AdminScreenController::UserList() {
    QStringList str;
    for(auto& s : Admin::GetUsersStringList()){
        str.append(QString::fromStdString(s));
    }
    return str;
}
