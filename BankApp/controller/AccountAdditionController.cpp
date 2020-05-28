#include "AccountAdditionController.h"

void AccountAdditionController::Initialize(QQmlApplicationEngine *p_engine) {
    rootObject = p_engine->rootObjects().first()->findChild<QObject*>("accountAddition");
    QObject* typeCombo = p_engine->rootObjects().first()->findChild<QObject*>("accTypeCombo");
    QObject* userCombo = p_engine->rootObjects().first()->findChild<QObject*>("ownerCombo");
    typeCombo->setProperty("model", QVariant::fromValue(accTypes()));
    userCombo->setProperty("model", QVariant::fromValue(userList()));
}

AccountAdditionController::AccountAdditionController(QQmlApplicationEngine *p_engine) {
    Initialize(p_engine);
}

QStringList AccountAdditionController::accTypes() {
    QStringList str;
    for(auto& s : AccountType::GetAllTypesStringList()){
        str.append(QString::fromStdString(s));
    }
    return str;
}

QStringList AccountAdditionController::userList() {
    QStringList str;
    for(auto& s : Admin::GetUsersStringList()){
        str.append(QString::fromStdString(s));
    }
    return str;
}
