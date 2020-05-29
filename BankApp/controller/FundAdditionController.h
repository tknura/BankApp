#ifndef FUNDADDITIONCONTROLLER_H
#define FUNDADDITIONCONTROLLER_H

#include <QString>
#include "IController.h"
#include "../model/enums/FundType.h"
#include "../model/Admin.h"

class FundAdditionController : public QObject, IController
{
    Q_OBJECT

private:
    QObject* rootObject;

public:
    void Initialize(QQmlApplicationEngine* p_engine) override;
    ~FundAdditionController() override {}
    FundAdditionController(QQmlApplicationEngine* p_engine);
    QStringList FundTypes();

public slots:
};

#endif // FUNDADDITIONCONTROLLER_H
