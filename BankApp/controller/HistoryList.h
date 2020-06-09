#ifndef HISTORYLIST_H
#define HISTORYLIST_H

#include <QObject>
#include <QVector>
#include <iostream>

#include "HistoryListModel.h"

struct HistoryItem
{
    QString name;
    QString description;
    QString amount;

};

class HistoryList : public QObject
{
    Q_OBJECT
public:
    explicit HistoryList(QObject *parent = nullptr);

    bool setItemAt(int index, const HistoryItem &item );
    void displaydupa(){std::cerr<<"DUPSKO";}

    QVector<HistoryItem> items() const;

signals:
    void preItemAppended();
    void postItemAppended();

public slots:
    void appendItem();
    bool AddItem(QString name = "default", QString description = "default", QString amount = "+00,00");
    void PrintItems();
    //QString GetItem(){return mItems[0].name;}


private:
    QVector <HistoryItem> mItems;

};

#endif // HISTORYLIST_H
