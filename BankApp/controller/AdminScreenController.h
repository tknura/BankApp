#ifndef ADMINSCREENCONTROLLER_H
#define ADMINSCREENCONTROLLER_H

#include <QObject>
#include <QQmlApplicationEngine>
#include "model/Admin.h"

class AdminScreenController : QObject
{
    Q_OBJECT

private:
    QObject *rootObject;
    AdminScreenController() {}
    AdminScreenController(const AdminScreenController &) : QObject() {}
    ~AdminScreenController() {}

public:
    static AdminScreenController &instance() {
        static AdminScreenController instance;
        return instance;
    }
    void initialize(QQmlApplicationEngine* p_engine);

public slots:
    void HandleUserAddition(QString, QString, QString);
};

#endif // ADMINSCREENCONTROLLER_H
