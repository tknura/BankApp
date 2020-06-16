#include "MainController.h"

void MainController::Initialize() { }

void MainController::Connections() {
    QObject::connect(rootObject,SIGNAL(logOut()),this,SLOT(MainController::HandleLogOutButton()));
}

void MainController::HandleLogOutButton() {
    Bank::GetLoggedUser<IUser>()->OnLogOut();
    QCoreApplication::exit();
}

MainController::MainController(QQmlApplicationEngine *p_engine) {
    this->rootObject = p_engine->rootObjects().first();
    this->engine = p_engine;
    this->lsc = new LogInScreenController(p_engine);
    Initialize();
}

MainController::~MainController() {
    delete this->lsc;
}
