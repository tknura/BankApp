#include "LogInSceneController.h"

LogInSceneController::LogInSceneController(QQmlApplicationEngine *p_engine)
    : engine(p_engine) {
    rootObject = engine->rootObjects().first();

    proceedButton = rootObject->findChild<QObject*>("proceedButton");
    loginInput = rootObject->findChild<QObject*>("loginInput");
    passwordInput = rootObject->findChild<QObject*>("passwordInput");

    QObject::connect(proceedButton, SIGNAL(clicked()), this, SLOT(HandleProceedButton()));
}

void LogInSceneController::HandleProceedButton() {
    if(loginInput && passwordInput){
        //TODO handling email creation
        LogInData attempt;
        attempt.SetLogin(loginInput->property("text").toString().toStdString());
        attempt.SetPassword(passwordInput->property("text").toString().toStdString());
        Authorization::LogInAttempt(attempt);
        //TODO handle changing qml scenes
    }
}
