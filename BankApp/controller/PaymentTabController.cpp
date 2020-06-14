#include "PaymentTabController.h"
#include "UserScreenController.h"
#include "AdminScreenController.h"

void PaymentTabController::Initialize() {
    rootObject->setProperty("userAccNumbersModel", QVariant::fromValue(UserScreenController::usrAccounts()));
}

void PaymentTabController::Connections() {
    QObject::connect(rootObject, SIGNAL(makePayment(QString,QString,QString,QString,QString,QString,QString)),
                     this, SLOT(handleMakePayment(QString,QString,QString,QString,QString,QString,QString)));
}

PaymentTabController::PaymentTabController(QQmlApplicationEngine *p_engine) {
    this->rootObject = p_engine->rootObjects().first()->findChild<QObject*>("payments");

    Initialize();
    Connections();
}

void PaymentTabController::handleMakePayment(QString outNum, QString amount, QString title, QString date,
                                             QString name, QString inNum, QString adress) {
    double damount = AdminScreenController::GetMoneyFromString(amount.toStdString());
    Bank::GetLoggedUser<User>()->MakePayment(outNum.toStdString(), damount, title.toStdString(), date.toStdString(),
                                             name.toStdString(), inNum.toStdString(), adress.toStdString());
}


