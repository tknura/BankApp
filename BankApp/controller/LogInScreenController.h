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
#include "model/JsonManager.h"

class LogInScreenController : public QObject, IController
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
    void Connections() override;
    ~LogInScreenController() override;
    void Initialize() override;

public slots:
    void HandleProceedButton();
    void LoadAttempt(QString, QString);
};
#endif // LOGINSCENECONTROLLER_H
