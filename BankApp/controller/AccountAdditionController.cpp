#include "AccountAdditionController.h"
#include "AdminScreenController.h"

void AccountAdditionController::Initialize() {
    typeCombo->setProperty("model", QVariant::fromValue(AccTypes()));
    rootObject->setProperty("usersModel", QVariant::fromValue(AdminScreenController::UserList()));
    accNumberInput->setProperty("inputText", QString::fromStdString(Account::GenerateNumber()));
}

void AccountAdditionController::Connections() {
    QObject::connect(rootObject, SIGNAL(newAccNumber()), this, SLOT(HandleReroll()));
    QObject::connect(rootObject, SIGNAL(refresh()), this, SLOT(HandleTabRefresh()));
    QObject::connect(rootObject, SIGNAL(addPersonalAcc(QString, QString, QString)),
                     this, SLOT(HandlePersonalAccAdd(QString, QString, QString)));
    QObject::connect(rootObject, SIGNAL(addSavingsAcc(QString, QString, QString, QString)),
                     this, SLOT(HandleSavingsAccAdd(QString, QString, QString, QString)));
    QObject::connect(rootObject, SIGNAL(addChildAcc(QString, QString, QString, QString, QString)),
                     this, SLOT(HandleChildAccAdd(QString, QString, QString, QString, QString)));
//    QObject::connect(rootObject, SIGNAL(addFamilyAcc(QString, QString, QString)),
//                     this, SLOT(HandleFamilyAccAdd(QString, QString, QString)));
}

AccountAdditionController::AccountAdditionController(QQmlApplicationEngine *p_engine) {
    this->rootObject = p_engine->rootObjects().first()->findChild<QObject*>("accountAddition");
    this->typeCombo = rootObject->findChild<QObject*>("accTypeCombo");
    this->accNumberInput = rootObject->findChild<QObject*>("accNumberInput");

    Initialize();
    Connections();
}

QStringList AccountAdditionController::AccTypes() {
    QStringList str;
    for(auto& s : AccountType::GetAllTypesStringList()){
        str.append(QString::fromStdString(s));
    }
    return str;
}

void AccountAdditionController::HandlePersonalAccAdd(QString num, QString user, QString balance) {
    int id = StringParser::GetIDFromUserString(user.toStdString());
    double dbalance = balance.toDouble();

    if(AdminScreenController::admin->AddAccount(id, num.toStdString(), dbalance)){
        QMetaObject::invokeMethod(rootObject, "success");
    }
    else {
        QMetaObject::invokeMethod(rootObject, "fail");
    }
}

void AccountAdditionController::HandleSavingsAccAdd(QString num, QString user, QString balance,
                                                    QString interest) {
    int id = StringParser::GetIDFromUserString(user.toStdString());
    double dinterest = interest.toDouble();
    double dbalance = balance.toDouble();
    if(AdminScreenController::admin->AddAccount(id, num.toStdString(), dbalance, dinterest)) {
        QMetaObject::invokeMethod(rootObject, "success");
    }
    else {
        QMetaObject::invokeMethod(rootObject, "fail");
    }
}
void AccountAdditionController::HandleChildAccAdd(QString num, QString user, QString balance,
                                                  QString dailyLim, QString parent) {
    int userId = StringParser::GetIDFromUserString(user.toStdString());
    double dbalance = balance.toDouble();
    double ddailyLim = dailyLim.toDouble();
    int parentId = StringParser::GetIDFromUserString(parent.toStdString());

    if(AdminScreenController::admin->AddAccount(parentId, userId, num.toStdString(), dbalance, ddailyLim)) {
        QMetaObject::invokeMethod(rootObject, "success");
    }
    else {
        QMetaObject::invokeMethod(rootObject, "fail");
    }

}

void AccountAdditionController::HandleFamilyAccAdd(QString num, QString user, QString balance) {
    //todo
}

void AccountAdditionController::HandleReroll() {
    accNumberInput->setProperty("inputText", QString::fromStdString(Account::GenerateNumber()));
}

void AccountAdditionController::HandleTabRefresh() {
    typeCombo->setProperty("model", QVariant::fromValue(AccTypes()));
    rootObject->setProperty("usersModel", QVariant::fromValue(AdminScreenController::UserList()));
}
