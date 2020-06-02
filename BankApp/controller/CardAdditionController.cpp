#include "CardAdditionController.h"
#include "AdminScreenController.h"

void CardAdditionController::Initialize() {
    rootObject->setProperty("accountsModel", QVariant::fromValue(AdminScreenController::AccList()));
    typeCombo->setProperty("model", QVariant::fromValue(CardTypes()));
    cardNumberInput->setProperty("inputText", QString::fromStdString(Card::GenerateNumber()));
    ccvNumberInput->setProperty("inputText", QString::fromStdString(Card::GenerateCCV()));
}

void CardAdditionController::Connections() {
    QObject::connect(rootObject, SIGNAL(newCardNumber()), this, SLOT(HandleCardReroll()));
    QObject::connect(rootObject, SIGNAL(newCcvNumber()), this, SLOT(HandleCcvReroll()));
    QObject::connect(rootObject, SIGNAL(addPrePaid(QString, QString, QString, QString)),
                     this, SLOT(HandlePrePaidAdd(QString, QString, QString, QString)));
    QObject::connect(rootObject, SIGNAL(addCredit(QString, QString, QString, QString, QString, QString)),
                     this, SLOT(HandleCreditAdd(QString, QString, QString, QString, QString, QString)));
    QObject::connect(rootObject, SIGNAL(addDebit(QString, QString, QString, QString, QString)),
                     this, SLOT(HandleDebitAdd(QString, QString, QString, QString, QString)));
}

CardAdditionController::CardAdditionController(QQmlApplicationEngine *p_engine) {
    this->rootObject = p_engine->rootObjects().first()->findChild<QObject*>("cardAddition");
    this->typeCombo = rootObject->findChild<QObject*>("cardTypeCombo");
    this->cardNumberInput = rootObject->findChild<QObject*>("cardNumberInput");
    this->ccvNumberInput = rootObject->findChild<QObject*>("ccvNumberInput");

    Initialize();
    Connections();
}

QStringList CardAdditionController::CardTypes() {
    QStringList str;
    for(auto& s : CardType::GetAllTypesStringList()){
        str.append(QString::fromStdString(s));
    }
    return str;
}

void CardAdditionController::HandleCardReroll() {
    cardNumberInput->setProperty("inputText", QString::fromStdString(Card::GenerateNumber()));
}

void CardAdditionController::HandleCcvReroll() {
    ccvNumberInput->setProperty("inputText", QString::fromStdString(Card::GenerateCCV()));
}

void CardAdditionController::HandlePrePaidAdd(QString p_num, QString p_ccv, QString p_accNum,
                                              QString p_transLim) {
    int ccv = std::stoi(p_ccv.toStdString());
    double transLim = AdminScreenController::GetMoneyFromString(p_transLim.toStdString());
    if(AdminScreenController::admin->AddCard(p_accNum.toStdString(), p_num.toStdString(), ccv, transLim)) {
        QMetaObject::invokeMethod(rootObject, "success");
    }
    else {
        QMetaObject::invokeMethod(rootObject, "fail");
    }
}

void CardAdditionController::HandleCreditAdd(QString p_num, QString p_ccv, QString p_accNum,
                                             QString p_transLim, QString p_maxCredit, QString p_billingDate) {
    int ccv = std::stoi(p_ccv.toStdString());
    double transLim = AdminScreenController::GetMoneyFromString(p_transLim.toStdString());
        double maxCredit = AdminScreenController::GetMoneyFromString(p_maxCredit.toStdString());
    if(AdminScreenController::admin->AddCard(p_accNum.toStdString(), p_num.toStdString(), ccv, transLim,
                                                  maxCredit, p_billingDate.toStdString())) {
        QMetaObject::invokeMethod(rootObject, "success");
    }
    else {
        QMetaObject::invokeMethod(rootObject, "fail");
    }
}

void CardAdditionController::HandleDebitAdd(QString p_num, QString p_ccv, QString p_accNum,
                                            QString p_transLim, QString p_maxDebt) {
    int ccv = std::stoi(p_ccv.toStdString());
    double transLim = AdminScreenController::GetMoneyFromString(p_transLim.toStdString());
    double maxDebt = AdminScreenController::GetMoneyFromString(p_maxDebt.toStdString());
    if(AdminScreenController::admin->AddCard(p_accNum.toStdString(), p_num.toStdString(), ccv, transLim, maxDebt)) {
        QMetaObject::invokeMethod(rootObject, "success");
    }
    else {
        QMetaObject::invokeMethod(rootObject, "fail");
    }
}
