#include "AdminScreenController.h"

void AdminScreenController::initialize(QQmlApplicationEngine *p_engine) {
    rootObject = p_engine->rootObjects().first()->findChild<QObject*>("adminScreen");

    QObject *userAdditionTab = rootObject->findChild<QObject*>("userAddition");
    QObject::connect(userAdditionTab, SIGNAL(userAddition(QString, QString, QString)),
                     this, SLOT(HandleUserAddition(QString, QString, QString)));
}

void AdminScreenController::HandleUserAddition(QString login, QString password,
                                               QString mail) {
    QObject *userAdditionTab = rootObject->findChild<QObject*>("userAddition");
    if(std::dynamic_pointer_cast<Admin>(Bank::currentlyLoggedUser)->CreateUser(
            login.toStdString(), password.toStdString(), mail.toStdString())){
        QMetaObject::invokeMethod(userAdditionTab, "success");
    }
    else {
        QMetaObject::invokeMethod(userAdditionTab, "fail");
    }
}
