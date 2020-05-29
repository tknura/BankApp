#include "AccountAdditionController.h"
#include "AdminScreenController.h"

void AccountAdditionController::Initialize(QQmlApplicationEngine *p_engine) {
    rootObject = p_engine->rootObjects().first()->findChild<QObject*>("accountAddition");
    QObject* typeCombo = rootObject->findChild<QObject*>("accTypeCombo");
    QObject* rerollButton = rootObject->findChild<QObject*>("rerollButton");
    accNumberInput = rootObject->findChild<QObject*>("accNumberInput");

    typeCombo->setProperty("model", QVariant::fromValue(AccTypes()));
    rootObject->setProperty("usersModel", QVariant::fromValue(AdminScreenController::UserList()));
    accNumberInput->setProperty("inputText", QString::fromStdString(Account::GenerateNumber()));
    QObject::connect(rerollButton, SIGNAL(clicked()), this, SLOT(HandleRerollButton()));
}

AccountAdditionController::AccountAdditionController(QQmlApplicationEngine *p_engine) {
    Initialize(p_engine);
}

QStringList AccountAdditionController::AccTypes() {
    QStringList str;
    for(auto& s : AccountType::GetAllTypesStringList()){
        str.append(QString::fromStdString(s));
    }
    return str;
}

void AccountAdditionController::HandleRerollButton() {
    accNumberInput->setProperty("inputText", QString::fromStdString(Account::GenerateNumber()));
}
