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

public slots:
    void handleMakePayment(QString outNum, QString amount, QString title, QString date,
                           QString name, QString inNum, QString adress);
};

#endif // PAYMENTTABCONTROLLER_H
