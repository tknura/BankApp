#include "Payment.h"

json Payment::SerializeToJson()
{
    json j{retriever.SerializeToJson()};
    j["title"] = title;
    j["date"] = date;
    j["amount"] = amount;

    return j;
}

