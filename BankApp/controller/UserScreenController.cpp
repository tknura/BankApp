#include "UserScreenController.h"

void UserScreenController::initialize(QQmlApplicationEngine *p_engine) {
    this->rootObject = p_engine->rootObjects().first()->findChild<QObject*>("adminScreen");
}
