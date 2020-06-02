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
    QObject* typeCombo;
    QObject* accNumberInput;

public:
    void Initialize() override;
    void Connections() override;
    ~AccountAdditionController() override {}
    AccountAdditionController(QQmlApplicationEngine* p_engine);
    QStringList AccTypes();

public slots:
    void HandlePersonalAccAdd(QString num, QString user, QString balance);
    void HandleSavingsAccAdd(QString num, QString user, QString balance,
                             QString interest);
    void HandleChildAccAdd(QString num, QString user, QString balance,
                           QString dailyLim, QString parent);
    //TODO
    void HandleFamilyAccAdd(QString num, QString user, QString balance);
    void HandleReroll();
};

#endif // ACCOUNTADDITIONCONTROLLER_H
