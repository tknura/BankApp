#include "UserScreenController.h"
#include <QQmlContext>


void UserScreenController::Initialize() {
}

void UserScreenController::Connections()
{
    QObject::connect(rootObject,SIGNAL(logOut()),this,SLOT(HandleLogOutButton()));
}

UserScreenController::UserScreenController(QQmlApplicationEngine *p_engine) {
    this->rootObject = p_engine->rootObjects().first()->findChild<QObject*>("userScreen");
    this->pmntTabControler = new PaymentTabController(p_engine);

    Initialize();
    Connections();
}

UserScreenController::~UserScreenController() {
    delete pmntTabControler;
}

QStringList UserScreenController::usrAccounts() {
    QStringList str;
    for(auto& s : *Bank::GetLoggedUser<User>()->GetAccountList()){
        str.append(QString::fromStdString(s));
    }
    return str;
}

void UserScreenController::HandleLogOutButton()
{
    Bank::LogOut();
}
