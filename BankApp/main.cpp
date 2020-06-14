 #include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "controller/MainController.h"
#include "controller/LogInScreenController.h"
#include "controller/UserScreenController.h"
#include "controller/AdminScreenController.h"
#include "controller/HistoryListModel.h"
#include "controller/AccountButtonModel.h"
#include "controller/FriendsListModel.h"

#include "model/Bank.h"
#include "model/Test.h"


int main(int argc, char *argv[])
{
    Bank::Start();
    Test::Run();
//  std::unordered_map<std::string,std::shared_ptr<IAccount>> test{};
//    std::list<std::string> test1{};
//    JsonManager manager{1};
//    manager.ParseData(test1,test);
//    manager.SerializeData(test,Config::accountJSONPath);
//    return 0;
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);


    QGuiApplication app(argc, argv);

    qmlRegisterType<HistoryListModel>("HistoryList",1,0,"HistoryListModel");
    qmlRegisterType<AccountButtonModel>("AccountButtonModel",1,0,"AccountButtonModel");
    qmlRegisterType<FriendsListModel>("FriendsList",1,0,"FriendsListModel");

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
