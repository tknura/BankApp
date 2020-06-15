#include "PaymentTabController.h"
#include "UserScreenController.h"
#include "AdminScreenController.h"

void PaymentTabController::Initialize() {
    rootObject->setProperty("userAccNumbersModel", QVariant::fromValue(UserScreenController::usrAccounts()));
}

void PaymentTabController::Connections() {
    QObject::connect(rootObject, SIGNAL(makePayment(QString,QString,QString,QString,QString,QString,QString)),
                     this, SLOT(handleMakePayment(QString,QString,QString,QString,QString,QString,QString)));
    QObject::connect(rootObject, SIGNAL(addFriend(QString,QString,QString)),
                     this, SLOT(handleFriendAddition(QString,QString,QString)));
}

PaymentTabController::PaymentTabController(QQmlApplicationEngine *p_engine) {
    this->rootObject = p_engine->rootObjects().first()->findChild<QObject*>("payments");

    Initialize();
    Connections();
}

void PaymentTabController::handleMakePayment(QString outNum, QString amount, QString title, QString date,
                                             QString name, QString inNum, QString adress) {
    double damount = StringParser::GetMoneyFromString(amount.toStdString());
    if(Bank::GetLoggedUser<User>()->MakePayment(outNum.toStdString(), damount, title.toStdString(), date.toStdString(),
                                                 name.toStdString(), inNum.toStdString(), adress.toStdString())) {
        QMetaObject::invokeMethod(rootObject, "paymentSuccess");
    }
    else {
        QMetaObject::invokeMethod(rootObject, "paymentFail");
    }
}

void PaymentTabController::handleFriendAddition(QString name, QString address, QString accNum) {
    if(Bank::GetLoggedUser<User>()->AddFriend(name.toStdString(), accNum.toStdString(), address.toStdString())){
        QMetaObject::invokeMethod(rootObject, "friendSuccess");
    }
    else {
        QMetaObject::invokeMethod(rootObject, "friendFail");
    }
}


