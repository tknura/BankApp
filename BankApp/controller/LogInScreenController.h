#ifndef LOGINSCENECONTROLLER_H
#define LOGINSCENECONTROLLER_H

#include <QObject>
#include <QQmlProperty>
#include <QQuickItem>
#include <QQmlApplicationEngine>
#include "UserScreenController.h"
#include "AdminScreenController.h"
#include "model/Authorization.h"
#include "model/LogInData.h"

class LogInScreenController : public QObject
{
    Q_OBJECT

private:
    QObject *rootObject;
    QObject *loginDataBoxes;
    QObject *proceedButton;
    QQmlApplicationEngine* engine;
    UserScreenController* usc;
    AdminScreenController* asc;
    LogInData attempt;
    void LoadUserScreen();
    void LoadAdminScreen();

public:
    LogInScreenController(QQmlApplicationEngine* p_engine);
    ~LogInScreenController();
    void Initialize(QQmlApplicationEngine* p_engine);

public slots:
    void HandleProceedButton();
    void LoadAttemt(QString, QString);
};
#endif // LOGINSCENECONTROLLER_H
