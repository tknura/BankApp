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
    std::cerr << loginInput << " " << passwordInput << std::endl;
    if(loginInput && passwordInput){
        //TODO handling email creation
        LogInData attempt;
        attempt.SetLogin(QQmlProperty::read(loginInput, "text").toString().toStdString());
        attempt.SetPassword(QQmlProperty::read(passwordInput, "text").toString().toStdString());
        std::cerr << attempt.GetLogin() << " " << attempt.GetPassword() << std::endl;
        if(Authorization::LogInAttempt(attempt)) {
            QMetaObject::invokeMethod(rootObject, "loggingPassed");
        }
        else {
            QMetaObject::invokeMethod(rootObject, "loggingFailed");
            std::cerr << "failed!" << std::endl;
        }
    }
}
