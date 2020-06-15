#include "AdminScreenController.h"

std::shared_ptr<Admin> AdminScreenController::admin = Bank::GetLoggedUser<Admin>();

void AdminScreenController::Initialize() { }

void AdminScreenController::Connections()
{
    QObject::connect(rootObject,SIGNAL(logOut()),this,SLOT(HandleLogOutButton()));
}

AdminScreenController::AdminScreenController(QQmlApplicationEngine *p_engine) {
    this->rootObject = p_engine->rootObjects().first()->findChild<QObject*>("adminScreen");

    this->usrAddTabController = new UserAdditionController(p_engine);
    this->accAddTabController = new AccountAdditionController(p_engine);
    this->cardAddTabController = new CardAdditionController(p_engine);
    this->fundAddTabController = new FundAdditionController(p_engine);

    Initialize();
    Connections();
}

AdminScreenController::~AdminScreenController() {
    delete usrAddTabController;
    delete accAddTabController;
    delete cardAddTabController;
    delete fundAddTabController;
}

QStringList AdminScreenController::UserList() {
    QStringList str;
    for(auto& s : Admin::GetUsersStringList()){
        str.append(QString::fromStdString(s));
    }
    return str;
}

QStringList AdminScreenController::AccList() {
    QStringList str;
    for(auto& s : Admin::GetAccStringList()){
        str.append(QString::fromStdString(s));
    }
    return str;
}

void AdminScreenController::HandleLogOutButton()
{
    Bank::GetLoggedUser<Admin>()->OnLogOut();
}
