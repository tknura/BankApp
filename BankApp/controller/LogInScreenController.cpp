#include "LogInScreenController.h"

void LogInScreenController::Initialize() { }

void LogInScreenController::HandleProceedButton() {
    if(attempt.GetLogin() != "" && attempt.GetPassword() != ""){
        //TODO handling email creation
        if(Authorization::LogInAttempt(attempt)) {
            QMetaObject::invokeMethod(rootObject, "loggingPassed");
            if(Bank::isUserLogged()){
                LoadUserScreen();
            }
            else if(Bank::isAdminLogged()) {
                LoadAdminScreen();
            }
            attempt = LogInData();
        }
        else {
            QMetaObject::invokeMethod(rootObject, "loggingFailed");
        }
    }
}

void LogInScreenController::LoadAttempt(QString login, QString password) {
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
                     this, SLOT(LoadAttempt(QString, QString)));
}

LogInScreenController::~LogInScreenController() {
    if(usc) {
        delete usc;
    }
    if(asc) {
        delete asc;
    }
}
