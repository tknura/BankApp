#ifndef USERSCREENCONTROLLER_H
#define USERSCREENCONTROLLER_H

#include <QObject>
#include <QQmlApplicationEngine>
#include "model/Admin.h"
class UserScreenController : QObject
{
    Q_OBJECT

private:
    QObject *rootObject;

    UserScreenController() {}
    UserScreenController(const UserScreenController &) : QObject() {}
    ~UserScreenController() {}

public:
    static UserScreenController &instance() {
        static UserScreenController instance;
        return instance;
    }
    void initialize(QQmlApplicationEngine* p_engine);

public slots:

};

#endif // USERSCREENCONTROLLER_H
