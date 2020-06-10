#include "LogInScreenController.h"

void LogInScreenController::Initialize() { }

void LogInScreenController::HandleProceedButton() {
    if(attempt.GetLogin() != "" && attempt.GetPassword() != ""){
        //TODO handling email creation
        if(Authorization::LogInAttempt(attempt)) {
            QMetaObject::invokeMethod(rootObject, "loggingPassed");
            if(Bank::isUserLogged()){

                LoadUserScreen();
                //Loading data from files
                JsonManager manager(attempt.GetID());
                //manager.ParseData(Bank::currentlyLoggedUser->GetAccountList()*,Bank::accountMap);
                //
                manager.ParseData(Bank::fundMap);
                manager.ParseData(Bank::cardMap);
            }
            else if(Bank::isAdminLogged()) {
                LoadAdminScreen();
            }
        }
        else {
            QMetaObject::invokeMethod(rootObject, "loggingFailed");
        }
    }
}

void LogInScreenController::LoadAttemt(QString login, QString password) {
    attempt.SetLogin(login.toStdString());
    attempt.SetPassword(password.toStdString());
}

void LogInScreenController::LoadUserScreen() {
    QMetaObject::invokeMethod(rootObject, "loadUserScreen");
    this->usc = new UserScreenController(engine);
}

void LogInScreenController::LoadAdminScreen() {
    QMetaObject::invokeMethod(rootObject, "loadAdminScreen");
    this->asc = new AdminScreenController(engine);
}

LogInScreenController::LogInScreenController(QQmlApplicationEngine *p_engine) {
    this->rootObject = p_engine->rootObjects().first()->findChild<QObject*>("loginScreen");
    this->engine = p_engine;
    this->proceedButton = rootObject->findChild<QObject*>("proceedButton");

    Initialize();
    Connections();
}

void LogInScreenController::Connections() {
    QObject::connect(proceedButton, SIGNAL(clicked()), this, SLOT(HandleProceedButton()));
    QObject::connect(rootObject, SIGNAL(inputValues(QString, QString)),
                     this, SLOT(LoadAttemt(QString, QString)));
}

LogInScreenController::~LogInScreenController() {
    if(usc) {
        delete usc;
    }
    if(asc) {
        delete asc;
    }
}
