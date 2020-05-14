#include "MainController.h"

void MainController::initialize(QQmlApplicationEngine *p_engine) {
    this->rootObject = p_engine->rootObjects().first();
    this->engine = p_engine;
    LogInScreenController::instance().initialize(p_engine);
}

void MainController::LoadUserScreen() {
    //TO DO load data to user screen here
    QMetaObject::invokeMethod(rootObject, "loadUserScreen");
    UserScreenController::instance().initialize(engine);
}

void MainController::LoadAdminScreen() {
    //TO DO load data to admin screen here
    QMetaObject::invokeMethod(rootObject, "loadAdminScreen");
    AdminScreenController::instance().initialize(engine);
}
