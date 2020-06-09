#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "controller/MainController.h"
#include "controller/LogInScreenController.h"
#include "controller/UserScreenController.h"
#include "controller/AdminScreenController.h"
#include "controller/HistoryListModel.h"
#include "controller/HistoryList.h"

#include "model/Bank.h"
#include "model/Test.h"


int main(int argc, char *argv[])
{
    Bank::Start();
    Test::Run();
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<HistoryListModel>("HistoryList",1,0,"HistoryListModel");
    qmlRegisterUncreatableType<HistoryList>("HistoryList",1,0, "HistoryList",QStringLiteral("HistoryList should not be created in QML"));





    QQmlApplicationEngine engine;


    HistoryList historyList;
    engine.rootContext()->setContextProperty(QStringLiteral("historyList"), &historyList);

    std::cerr<<"dupa3";
    //history list exposed to QML(Avalible to any QML file loaded by the app)


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
