#include "UserAdditionController.h"
#include "../model/Admin.h"

void UserAdditionController::Initialize(QQmlApplicationEngine *p_engine) {
    rootObject = p_engine->rootObjects().first()->findChild<QObject*>("userAddition");
    QObject::connect(rootObject, SIGNAL(userAddition(QString, QString, QString)),
                     this, SLOT(HandleUserAddition(QString, QString, QString)));
}

UserAdditionController::UserAdditionController(QQmlApplicationEngine *p_engine) {
    Initialize(p_engine);
}

void UserAdditionController::HandleUserAddition(QString login, QString password, QString mail) {
    QObject *userAdditionTab = rootObject->findChild<QObject*>("userAddition");
    if(std::dynamic_pointer_cast<Admin>(Bank::currentlyLoggedUser)->CreateUser(
            login.toStdString(), password.toStdString(), mail.toStdString())){
        QMetaObject::invokeMethod(userAdditionTab, "success");
    }
    else {
        QMetaObject::invokeMethod(userAdditionTab, "fail");
    }
}
