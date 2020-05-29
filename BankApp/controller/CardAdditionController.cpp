#include "CardAdditionController.h"
#include "AdminScreenController.h"

void CardAdditionController::Initialize(QQmlApplicationEngine *p_engine) {
    rootObject = p_engine->rootObjects().first()->findChild<QObject*>("cardAddition");
    QObject* typeCombo = rootObject->findChild<QObject*>("cardTypeCombo");
    QObject* cardRerollButton = rootObject->findChild<QObject*>("cardRerollButton");
    QObject* ccvRerollButton = rootObject->findChild<QObject*>("ccvRerollButton");
    cardNumberInput = rootObject->findChild<QObject*>("cardNumberInput");
    ccvNumberInput = rootObject->findChild<QObject*>("ccvNumberInput");

    typeCombo->setProperty("model", QVariant::fromValue(CardTypes()));
    cardNumberInput->setProperty("inputText", QString::fromStdString(Card::GenerateNumber()));
    ccvNumberInput->setProperty("inputText", QString::fromStdString(Card::GenerateCCV()));
    QObject::connect(cardRerollButton, SIGNAL(clicked()), this, SLOT(HandleCardRerollButton()));
    QObject::connect(ccvRerollButton, SIGNAL(clicked()), this, SLOT(HandleCcvRerollButton()));
}

CardAdditionController::CardAdditionController(QQmlApplicationEngine *p_engine) {
    Initialize(p_engine);
}

QStringList CardAdditionController::CardTypes() {
    QStringList str;
    for(auto& s : CardType::GetAllTypesStringList()){
        str.append(QString::fromStdString(s));
    }
    return str;
}

void CardAdditionController::HandleCardRerollButton() {
    cardNumberInput->setProperty("inputText", QString::fromStdString(Card::GenerateNumber()));
}

void CardAdditionController::HandleCcvRerollButton() {
    ccvNumberInput->setProperty("inputText", QString::fromStdString(Card::GenerateCCV()));
}
