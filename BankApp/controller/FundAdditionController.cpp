#include "FundAdditionController.h"
#include "AdminScreenController.h"

void FundAdditionController::Initialize(QQmlApplicationEngine *p_engine) {
    rootObject = p_engine->rootObjects().first()->findChild<QObject*>("fundAddition");
    QObject* typeCombo = rootObject->findChild<QObject*>("fundTypeCombo");
    typeCombo->setProperty("model", QVariant::fromValue(FundTypes()));
    rootObject->setProperty("usersModel", QVariant::fromValue(AdminScreenController::UserList()));
}

FundAdditionController::FundAdditionController(QQmlApplicationEngine *p_engine) {
    Initialize(p_engine);
}

QStringList FundAdditionController::FundTypes() {
    QStringList str;
    for(auto& s : FundType::GetAllTypesStringList()){
        str.append(QString::fromStdString(s));
    }
    return str;
}
