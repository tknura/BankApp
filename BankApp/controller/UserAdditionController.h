#ifndef USERADDITIONCONTROLLER_H
#define USERADDITIONCONTROLLER_H

#include <QString>
#include "IController.h"
#include "../model/enums/AccountType.h"

class UserAdditionController : public QObject, IController
{
    Q_OBJECT

private:
    QObject* rootObject;
    QObject* cardNumberInput;

public:
    void Initialize(QQmlApplicationEngine* p_engine) override;
    ~UserAdditionController() override {}
    UserAdditionController(QQmlApplicationEngine* p_engine);

public slots:
    void HandleUserAddition(QString, QString, QString);
};
#endif // USERADDITIONCONTROLLER_H
