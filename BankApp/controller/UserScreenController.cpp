#include "UserScreenController.h"
#include <QQmlContext>


void UserScreenController::Initialize() {

//    HistoryList historyList;
//    p_engine->rootContext()->setContextProperty(QStringLiteral("historyList"), &historyList);
   // rootObject->findChild<QObject*>("history")->setProperty("historylist",QVariant::fromValue(&historyList));

}

void UserScreenController::Connections() {

}

UserScreenController::UserScreenController(QQmlApplicationEngine *p_engine) {
    this->rootObject = p_engine->rootObjects().first()->findChild<QObject*>("adminScreen");
    Initialize();
}
