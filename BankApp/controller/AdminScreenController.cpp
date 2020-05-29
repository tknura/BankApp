#include "AdminScreenController.h"

void AdminScreenController::Initialize(QQmlApplicationEngine *p_engine) {
    rootObject = p_engine->rootObjects().first()->findChild<QObject*>("adminScreen");
    QObject *userAdditionTab = rootObject->findChild<QObject*>("userAddition");
    QObject::connect(userAdditionTab, SIGNAL(userAddition(QString, QString, QString)),
                     this, SLOT(HandleUserAddition(QString, QString, QString)));
    accAddTabController = new AccountAdditionController(p_engine);
    cardAddTabController = new CardAdditionController(p_engine);
}

AdminScreenController::AdminScreenController(QQmlApplicationEngine *p_engine) {
    Initialize(p_engine);
}

AdminScreenController::~AdminScreenController() {
    delete accAddTabController;
    delete cardAddTabController;
}

QStringList AdminScreenController::UserList() {
    QStringList str;
    for(auto& s : Admin::GetUsersStringList()){
        str.append(QString::fromStdString(s));
    }
    return str;
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
