#ifndef LOGINSCENECONTROLLER_H
#define LOGINSCENECONTROLLER_H

#include <QObject>
#include <QQuickItem>
#include <QQmlApplicationEngine>
#include "model/Authorization.h"
#include "model/LogInData.h"

class LogInSceneController : public QObject
{
    Q_OBJECT
private:
    QObject *rootObject;
    QObject *proceedButton;
    QObject *loginInput;
    QObject *passwordInput;
public:
    LogInSceneController(QQmlApplicationEngine* p_engine);
    QQmlApplicationEngine* engine;

public slots:
    void HandleProceedButton();
};

#endif // LOGINSCENECONTROLLER_H
