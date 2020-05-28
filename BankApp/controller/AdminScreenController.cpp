#include "AdminScreenController.h"

void AdminScreenController::Initialize(QQmlApplicationEngine *p_engine) {
    rootObject = p_engine->rootObjects().first()->findChild<QObject*>("adminScreen");
    QObject *userAdditionTab = rootObject->findChild<QObject*>("userAddition");
    QObject::connect(userAdditionTab, SIGNAL(userAddition(QString, QString, QString)),
                     this, SLOT(HandleUserAddition(QString, QString, QString)));
    accAddTabController = new AccountAdditionController(p_engine);
//    QStringList str;
//    for(auto& s : AccountType::GetAllTypesStringList()){
//        str.push_back(QString::fromStdString(s));
//    }
//    QObject *accTypeCombo = accountAdditionTab->findChild<QObject*>("accTypeCombo");
//    QQmlContext *context =  QQmlEngine::contextForObject(accTypeCombo);
//    std::cerr << "accAdd: " << accountAdditionTab << " accTypeCombo: " << accTypeCombo << " context:" << context->nameForObject(accTypeCombo).toStdString();
    //    context->setContextProperty("typesList", QVariant::fromValue(str));
}

AdminScreenController::AdminScreenController(QQmlApplicationEngine *p_engine) {
    Initialize(p_engine);
}

AdminScreenController::~AdminScreenController() {
    delete accAddTabController;
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
