#include "UserScreenController.h"

void UserScreenController::Initialize() { }

void UserScreenController::Connections() { }

UserScreenController::UserScreenController(QQmlApplicationEngine *p_engine) {
    this->rootObject = p_engine->rootObjects().first()->findChild<QObject*>("userScreen");

    Initialize();
    Connections();
}
