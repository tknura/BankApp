#ifndef LOGINSCENECONTROLLER_H
#define LOGINSCENECONTROLLER_H

#include <QObject>
#include <QQmlProperty>
#include <QQuickItem>
#include <QQmlApplicationEngine>
#include "MainController.h"
#include "model/Authorization.h"
#include "model/LogInData.h"

class LogInScreenController : public QObject
{
    Q_OBJECT
private:
    QObject *rootObject;
    QObject *loginDataBoxes;
    QObject *proceedButton;
    LogInData attempt;
    LogInScreenController() {}
    LogInScreenController(const LogInScreenController &) : QObject() {}
    ~LogInScreenController() {}

public:
    static LogInScreenController &instance() {
        static LogInScreenController instance;
        return instance;
    }
    void initialize(QQmlApplicationEngine* p_engine);

public slots:
    void HandleProceedButton();
    void LoadAttemt(QString, QString);
};
#endif // LOGINSCENECONTROLLER_H
