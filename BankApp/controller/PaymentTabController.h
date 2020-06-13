#ifndef PAYMENTTABCONTROLLER_H
#define PAYMENTTABCONTROLLER_H

#include "IController.h"
#include <QObject>

class PaymentTabController : public QObject, IController
{
    Q_OBJECT

private:
    QObject* rootObject;

public:
    void Initialize() override;
    void Connections() override;
    ~PaymentTabController() override {}
    PaymentTabController(QQmlApplicationEngine* p_engine);
signals:

};

#endif // PAYMENTTABCONTROLLER_H
