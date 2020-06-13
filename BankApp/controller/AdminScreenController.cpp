#include "AdminScreenController.h"

std::shared_ptr<Admin> AdminScreenController::admin = Bank::GetLoggedUser<Admin>();

void AdminScreenController::Initialize() { }

void AdminScreenController::Connections() { }

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

int AdminScreenController::GetIDFromUserString(std::string str) {
    std::regex reg("\\d+");
    std::smatch sm;
    std::regex_search(str, sm, reg);
    return(std::stoi(sm[0].str()));
}

double AdminScreenController::GetPercentageFromString(std::string str) {
    std::regex reg("\\d+(?:\\.\\d+)?");
    std::smatch sm;
    std::regex_search(str, sm, reg);
    return(std::stod(sm[0].str()));
}

double AdminScreenController::GetMoneyFromString(std::string str) {
    std::regex reg("([+-]?[0-9]+(\\.[0-9]{2})?)");
    std::smatch sm;
    std::regex_search(str, sm, reg);
    return(std::stod(sm[0].str()));
}
