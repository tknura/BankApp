#ifndef ADMINSCREENCONTROLLER_H
#define ADMINSCREENCONTROLLER_H

#include <QObject>
#include <QQmlContext>
#include <QStringListModel>
#include <iostream>
#include "IController.h"
#include "model/Admin.h"
#include "model/enums/AccountType.h"

class AdminScreenController : QObject, IController
{
    Q_OBJECT

private:
    QObject *rootObject;

public:
    void Initialize(QQmlApplicationEngine* p_engine) override;
    AdminScreenController(QQmlApplicationEngine* p_engine);
    ~AdminScreenController() override {}

public slots:
    void HandleUserAddition(QString, QString, QString);
};

#endif // ADMINSCREENCONTROLLER_H
