#include "MainController.h"

QObject* MainController::rootObject = nullptr;

MainController::MainController(QQmlApplicationEngine* p_engine) {
    rootObject = p_engine->rootObjects().first();
}

void MainController::LoadUserScreen() {
    //TO DO load data to user screen here
    QMetaObject::invokeMethod(rootObject, "loadUserScreen");
}

void MainController::LoadAdminScreen() {
    //TO DO load data to admin screen here
    QMetaObject::invokeMethod(rootObject, "loadAdminScreen");
}
