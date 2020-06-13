#include "PaymentTabController.h"
#include "UserScreenController.h"

void PaymentTabController::Initialize() {
    rootObject->setProperty("userAccNumbersModel", QVariant::fromValue(UserScreenController::usrAccounts()));
}

void PaymentTabController::Connections() {

}

PaymentTabController::PaymentTabController(QQmlApplicationEngine *p_engine) {
    this->rootObject = p_engine->rootObjects().first()->findChild<QObject*>("payments");

    Initialize();
    Connections();
}
