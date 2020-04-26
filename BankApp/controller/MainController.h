#ifndef MAINCONTROLLER_H
#define MAINCONTROLLER_H

#include <QObject>
#include <QQmlApplicationEngine>

class MainController : public QObject
{
    Q_OBJECT

private:
    static QObject *rootObject;
public:
    MainController(QQmlApplicationEngine* p_engine);
    static void LoadUserScreen();
    static void LoadAdminScreen();
};

#endif // MAINCONTROLLER_H
