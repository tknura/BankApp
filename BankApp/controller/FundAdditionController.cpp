#include "FundAdditionController.h"
#include "AdminScreenController.h"

void FundAdditionController::Initialize() {
    typeCombo->setProperty("model", QVariant::fromValue(FundTypes()));
    rootObject->setProperty("usersModel", QVariant::fromValue(AdminScreenController::UserList()));
}

void FundAdditionController::Connections() {
    QObject::connect(rootObject, SIGNAL(addInvestment(QString, QString, QString, QString, QString)),
                     this, SLOT(HandleInvestmentAdd(QString, QString, QString, QString, QString)));
    QObject::connect(rootObject, SIGNAL(addSavings(QString, QString, QString, QString, QString, QString, QString)),
                     this, SLOT(HandleSavingsAdd(QString, QString, QString, QString, QString, QString, QString)));
    QObject::connect(rootObject, SIGNAL(addSavings(QString, QString, QString, QString, QString, QString, QString, QString)),
                     this, SLOT(HandleSavingsAdd(QString, QString, QString, QString, QString, QString, QString, QString)));
}

FundAdditionController::FundAdditionController(QQmlApplicationEngine *p_engine) {
    this->rootObject = p_engine->rootObjects().first()->findChild<QObject*>("fundAddition");
    this->typeCombo = rootObject->findChild<QObject*>("fundTypeCombo");

    Initialize();
    Connections();
}

QStringList FundAdditionController::FundTypes() {
    QStringList str;
    for(auto& s : FundType::GetAllTypesStringList()){
        str.append(QString::fromStdString(s));
    }
    return str;
}

void FundAdditionController::HandleInvestmentAdd(QString p_usrId, QString p_minAmount, QString p_balance,
                                                 QString p_maxRate, QString p_fee) {
    int userId = AdminScreenController::GetIDFromUserString(p_usrId.toStdString());
    double minAmount = AdminScreenController::GetMoneyFromString(p_minAmount.toStdString());
    double maxRate = AdminScreenController::GetPercentageFromString(p_maxRate.toStdString());
    double fee = AdminScreenController::GetPercentageFromString(p_fee.toStdString());
    double balance = AdminScreenController::GetMoneyFromString(p_balance.toStdString());
    if(AdminScreenController::admin->AddFund(userId, minAmount, maxRate, fee, balance)){
        QMetaObject::invokeMethod(rootObject, "success");
    }
    else {
        QMetaObject::invokeMethod(rootObject, "fail");
    }
}

void FundAdditionController::HandleSavingsAdd(QString p_usrId, QString p_minAmount, QString p_maxRate,
                                              QString p_balance, QString p_fee, QString p_startDate, QString p_endDate) {
    int userId = AdminScreenController::GetIDFromUserString(p_usrId.toStdString());
    double minAmount = AdminScreenController::GetMoneyFromString(p_minAmount.toStdString());
    double maxRate = AdminScreenController::GetPercentageFromString(p_maxRate.toStdString());
    double fee = AdminScreenController::GetPercentageFromString(p_fee.toStdString());
    double balance = AdminScreenController::GetMoneyFromString(p_balance.toStdString());
    if(AdminScreenController::admin->AddFund(userId, minAmount, maxRate, fee, balance,
                                              p_startDate.toStdString(), p_endDate.toStdString())){
        QMetaObject::invokeMethod(rootObject, "success");
    }
    else {
        QMetaObject::invokeMethod(rootObject, "fail");
    }
}

void FundAdditionController::HandleRetirementAdd(QString p_usrId, QString p_minAmount, QString p_maxRate,
                                                 QString p_balance, QString p_fee, QString p_monthlyIn,
                                                 QString p_retired) {
    int userId = AdminScreenController::GetIDFromUserString(p_usrId.toStdString());
    double minAmount = AdminScreenController::GetMoneyFromString(p_minAmount.toStdString());
    double maxRate = AdminScreenController::GetPercentageFromString(p_maxRate.toStdString());
    double fee = AdminScreenController::GetPercentageFromString(p_fee.toStdString());
    double balance = AdminScreenController::GetMoneyFromString(p_balance.toStdString());
    double monthlyIn = AdminScreenController::GetMoneyFromString(p_monthlyIn.toStdString());
    bool isRetired = (p_retired == "Yes") ? true : false;
    if(AdminScreenController::admin->AddFund(userId, minAmount, maxRate, fee, balance,isRetired,
                                              monthlyIn)){
        QMetaObject::invokeMethod(rootObject, "success");
    }
    else {
        QMetaObject::invokeMethod(rootObject, "fail");
    }
}
