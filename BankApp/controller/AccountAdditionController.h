#ifndef ACCOUNTADDITIONCONTROLLER_H
#define ACCOUNTADDITIONCONTROLLER_H

#include <QString>
#include "IController.h"
#include "../model/enums/AccountType.h"
#include "../model/Admin.h"

class AccountAdditionController : QObject, IController
{
    Q_OBJECT

private:
    QObject* rootObject;
    QObject* accNumberInput;
public:
    void Initialize(QQmlApplicationEngine* p_engine) override;
    ~AccountAdditionController() override {}
    AccountAdditionController(QQmlApplicationEngine* p_engine);
    QStringList AccTypes();

public slots:
    void HandleRerollButton();
};

#endif // ACCOUNTADDITIONCONTROLLER_H
