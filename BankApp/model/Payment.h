#ifndef PAYMENT_H
#define PAYMENT_H

#include <string>
#include "PaymentRetriever.h"
#include "IValidator.h"
#include "json.hpp"
#include <QString>

class Payment //: IValidator
{
public:
    Payment(){std::cerr<<"Payment object created\n";}
    //~Payment() override;
    double amount;
    std::string title;
    std::string date;
    PaymentRetriever retriever;//potrzebny konstruktor kopiujący i przenoszący
    bool incoming;
    //bool IsValid() override;

    Payment(double p_amount, std::string p_title, std::string p_date, std::string p_name, std::string p_accNum, std::string p_address,bool p_incoming)
        :amount(p_amount),title(p_title), date(p_date), retriever(p_name,p_accNum,p_address),incoming(p_incoming) {std::cerr<<"Payment object created\n";}

    std::string GetAccNumber(){return retriever.GetAccNumer();}
    double GetAmount(){return amount;} 
    QString GetDescription(){return QString::fromStdString(title);}
    QString GetDate(){return QString::fromStdString(date);}
    std::string GetDateStr(){return date;}
    QString GetName(){return QString::fromStdString(retriever.GetName());}

    json SerializeToJson();
};

#endif // PAYMENT_H
