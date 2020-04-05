#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "controller/LogInSceneController.h"
#include "model/Bank.h"
#include "model/Test.h"

int main(int argc, char *argv[])
{
    Bank::Start();
    Test::Run();
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/view/LoginScene.qml"));

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);
    engine.load(url);
    LogInSceneController lsc(&engine);

    return app.exec();
}
