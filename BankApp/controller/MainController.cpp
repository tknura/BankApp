#include "MainController.h"

void MainController::Initialize(QQmlApplicationEngine *p_engine) {
    this->rootObject = p_engine->rootObjects().first();
    this->engine = p_engine;
    this->lsc = new LogInScreenController(p_engine);
}

MainController::MainController(QQmlApplicationEngine *p_engine) {
    Initialize(p_engine);
}

MainController::~MainController() {
    delete this->lsc;
}
