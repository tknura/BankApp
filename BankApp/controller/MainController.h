#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include "LogInScreenController.h"
#include "AdminScreenController.h"
#include "UserScreenController.h"
#include <QObject>
#include <QQmlApplicationEngine>

class MainController : public QObject
{
    Q_OBJECT

private:
    QObject *rootObject;
    QQmlApplicationEngine* engine;
    MainController() {}
    MainController(const MainController &) : QObject() {}
    ~MainController() {}

public:
    static MainController &instance() {
        static MainController instance;
        return instance;
    }

    void initialize(QQmlApplicationEngine* p_engine);
    void LoadUserScreen();
    void LoadAdminScreen();
    QObject* GetRootObject();
};

#endif // MAINCONTROLLER_H
