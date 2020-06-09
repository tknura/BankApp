#include "HistoryList.h"
#include <iostream>

HistoryList::HistoryList(QObject *parent) : QObject(parent)
{
    mItems.append({QStringLiteral("Stanisław"),QStringLiteral("Lidl"),QStringLiteral("+44,88")});
    mItems.append({QStringLiteral("Stansaw"),QStringLiteral("Lidl"),QStringLiteral("+44,88")});
    mItems.append({QStringLiteral("Stanisław"),QStringLiteral("Lidl"),QStringLiteral("+44,88")});
    mItems.append({QStringLiteral("Stanisław"),QStringLiteral("Lidl"),QStringLiteral("+44,88")});
    mItems.append({QStringLiteral("Stanisław"),QStringLiteral("Lidl"),QStringLiteral("+44,88")});
    mItems.append({QStringLiteral("Stanisław"),QStringLiteral("Lidl"),QStringLiteral("+44,88")});
    std::cerr<<"dupa2";
}

bool HistoryList::setItemAt(int index, const HistoryItem &item)
{
     if(index < 0 or index >= mItems.size())
     {
         return false;
     }

     const HistoryItem &oldItem = mItems.at(index);
     if(item.name==oldItem.name and item.amount==oldItem.amount and item.description == oldItem.description)
     {
         return false;
     }

     mItems[index] = item;
     return true;
}

QVector<HistoryItem> HistoryList::items() const
{
    return  mItems;


}

void HistoryList::appendItem()
{
    emit preItemAppended();

    HistoryItem item;

    mItems.append(item);

    emit postItemAppended();

}

bool HistoryList::AddItem(QString name, QString description, QString amount)
{
    mItems.append({name,description,amount});
    return true;

}

void HistoryList::PrintItems()
{
    for(auto p : mItems)
    {
        std::cerr<<"\n"<<(p.name).toStdString()<<" "<<(p.amount).toStdString();

    }
}

