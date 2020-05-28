#ifndef ACCOUNTADDITIONCONTROLLER_H
#define ACCOUNTADDITIONCONTROLLER_H

#include <QString>
#include <QQuickView>
#include "IController.h"
#include "../model/enums/AccountType.h"
#include "../model/Admin.h"

class AccountAdditionController : QObject, IController
{
    Q_OBJECT

private:
    QObject* rootObject;

public:
    void Initialize(QQmlApplicationEngine* p_engine) override;
    ~AccountAdditionController() override {}
    AccountAdditionController(QQmlApplicationEngine* p_engine);
    QStringList accTypes();
    QStringList userList();
};

#endif // ACCOUNTADDITIONCONTROLLER_H
