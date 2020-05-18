#include "UserScreenController.h"

void UserScreenController::Initialize(QQmlApplicationEngine *p_engine) {
    this->rootObject = p_engine->rootObjects().first()->findChild<QObject*>("adminScreen");
}

UserScreenController::UserScreenController(QQmlApplicationEngine *p_engine) {
    Initialize(p_engine);
}
