#ifndef PAYMENT_H
#define PAYMENT_H

#include <string>
#include "PaymentRetriever.h"
#include "IValidator.h"
#include "json.hpp"
#include <QString>

using str = std::string;

class Payment //: IValidator
{
public:
    Payment(){std::cerr<<"Payment object created\n";}
    //~Payment() override;
    double amount;
    str title;
    str date;
    PaymentRetriever retriever;//potrzebny konstruktor kopiujący i przenoszący
    //bool IsValid() override;

    Payment(double p_amount, str p_title, str p_date, str p_name, str p_accNum, str p_address)
        :amount(p_amount),title(p_title), date(p_date), retriever(p_name,p_accNum,p_address){std::cerr<<"Payment object created\n";}

    str GetAccNumber(){return retriever.GetAccNumer();}
    double GetAmount(){return amount;} 
    QString GetDescription(){return QString::fromStdString(title);}
    QString GetDate(){return QString::fromStdString(date);}
    QString GetName(){return QString::fromStdString(retriever.GetName());}

    json SerializeToJson();
};

#endif // PAYMENT_H
