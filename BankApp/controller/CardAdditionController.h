#ifndef CARDADDITIONCONTROLLER_H
#define CARDADDITIONCONTROLLER_H

#include <QObject>
#include <QString>
#include "IController.h"
#include "../model/enums/CardType.h"
#include "../model/Admin.h"

class CardAdditionController : public QObject, IController
{
    Q_OBJECT

private:
    QObject* rootObject;
    QObject* typeCombo;
    QObject* cardNumberInput;
    QObject* ccvNumberInput;

public:
    void Initialize() override;
    void Connections() override;
    ~CardAdditionController() override {}
    CardAdditionController(QQmlApplicationEngine* p_engine);
    QStringList CardTypes();

public slots:
    void HandleCardReroll();
    void HandleCcvReroll();
    void HandlePrePaidAdd(QString p_num, QString p_ccv, QString p_accNum, QString p_transLim);
    void HandleCreditAdd(QString p_num, QString p_ccv, QString p_accNum,
                         QString p_transLim, QString p_maxCredit, QString p_billingDate);
    void HandleDebitAdd(QString p_num, QString p_ccv, QString p_accNum,
                        QString p_transLim, QString p_maxDebt);
    void HandleTabRefresh();
};

#endif // CARDADDITIONCONTROLLER_H
