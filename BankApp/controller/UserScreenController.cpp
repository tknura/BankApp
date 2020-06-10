#include "UserScreenController.h"
#include "HistoryList.h"
#include <QQmlContext>


void UserScreenController::Initialize(QQmlApplicationEngine *p_engine) {
    this->rootObject = p_engine->rootObjects().first()->findChild<QObject*>("adminScreen");
//    HistoryList historyList;
//    p_engine->rootContext()->setContextProperty(QStringLiteral("historyList"), &historyList);
   // rootObject->findChild<QObject*>("history")->setProperty("historylist",QVariant::fromValue(&historyList));

}

UserScreenController::UserScreenController(QQmlApplicationEngine *p_engine) {
    Initialize(p_engine);
}
