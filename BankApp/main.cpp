#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "controller/MainController.h"
#include "controller/LogInScreenController.h"
#include "controller/UserScreenController.h"
#include "controller/AdminScreenController.h"
#include "controller/HistoryListModel.h"

#include "model/Bank.h"
#include "model/Test.h"


int main(int argc, char *argv[])
{
    Bank::Start();
    Test::Run();

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);


    QGuiApplication app(argc, argv);

    qmlRegisterType<HistoryListModel>("HistoryList",1,0,"HistoryListModel");

    QQmlApplicationEngine engine;
    engine.addImportPath("qrc:/");
    const QUrl url(QStringLiteral("qrc:/screens/main.qml"));

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl){
                QCoreApplication::exit(-1);
            }
        }, Qt::QueuedConnection);


    engine.load(url);
    MainController msc(&engine);
    return app.exec();
}
