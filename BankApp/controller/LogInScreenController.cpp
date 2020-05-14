#include "LogInScreenController.h"

void LogInScreenController::initialize(QQmlApplicationEngine *p_engine) {
    rootObject = p_engine->rootObjects().first()->findChild<QObject*>("loginScreen");

    proceedButton = rootObject->findChild<QObject*>("proceedButton");

    QObject::connect(proceedButton, SIGNAL(clicked()), this, SLOT(HandleProceedButton()));
    QObject::connect(rootObject, SIGNAL(inputValues(QString, QString)),
                     this, SLOT(LoadAttemt(QString, QString)));
}

void LogInScreenController::HandleProceedButton() {
    if(attempt.GetLogin() != "" && attempt.GetPassword() != ""){
        //TODO handling email creation
        if(Authorization::LogInAttempt(attempt)) {
            QMetaObject::invokeMethod(rootObject, "loggingPassed");
            if(Bank::isUserLogged()){
                MainController::instance().LoadUserScreen();
            }
            else if(Bank::isAdminLogged()) {
                MainController::instance().LoadAdminScreen();
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
