#ifndef FUNDADDITIONCONTROLLER_H
#define FUNDADDITIONCONTROLLER_H

#include <QString>
#include "IController.h"
#include "../model/StringParser.h"
#include "../model/enums/FundType.h"
#include "../model/Admin.h"

class FundAdditionController : public QObject, IController
{
    Q_OBJECT

private:
    QObject* rootObject;
    QObject* typeCombo;

public:
    void Initialize() override;
    void Connections() override;
    ~FundAdditionController() override {}
    FundAdditionController(QQmlApplicationEngine* p_engine);
    QStringList FundTypes();

public slots:
//    void HandleInvestmentAdd(QString p_usrId, QString p_minAmount, QString p_maxRate,
//                             QString p_balance, QString p_fee);
    void HandleSavingsAdd(QString p_usrId, QString p_minAmount, QString p_maxRate,
                          QString p_balance, QString p_fee, QString p_startDate, QString p_endDate);
    void HandleRetirementAdd(QString p_usrId, QString p_minAmount, QString p_maxRate, QString p_fee,
                             QString p_balance, QString p_monthlyIn,
                             QString p_retired);
    void HandleTabRefresh();
};

#endif // FUNDADDITIONCONTROLLER_H
