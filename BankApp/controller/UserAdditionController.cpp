#include "UserAdditionController.h"
#include "../model/Admin.h"

void UserAdditionController::Initialize() { }

void UserAdditionController::Connections() {
    QObject::connect(rootObject, SIGNAL(userAddition(QString, QString, QString)),
                     this, SLOT(HandleUserAddition(QString, QString, QString)));
}

UserAdditionController::UserAdditionController(QQmlApplicationEngine *p_engine) {
    this->rootObject = p_engine->rootObjects().first()->findChild<QObject*>("userAddition");

    Initialize();
    Connections();
}

void UserAdditionController::HandleUserAddition(QString login, QString password, QString mail) {
    if(Bank::GetLoggedUser<Admin>()->CreateUser(
            login.toStdString(), password.toStdString(), mail.toStdString())){
        QMetaObject::invokeMethod(rootObject, "success");
    }
    else {
        QMetaObject::invokeMethod(rootObject, "fail");
    }
}
