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
    QObject* cardNumberInput;
    QObject* ccvNumberInput;

public:
    void Initialize(QQmlApplicationEngine* p_engine) override;
    ~CardAdditionController() override {}
    CardAdditionController(QQmlApplicationEngine* p_engine);
    QStringList CardTypes();

public slots:
    void HandleCardRerollButton();
    void HandleCcvRerollButton();
};

#endif // CARDADDITIONCONTROLLER_H
