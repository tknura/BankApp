#include "HistoryListModel.h"
#include "model/Account.h"
#include "model/History.h"


#include <iostream>

HistoryListModel::HistoryListModel(QObject *parent)
    : QAbstractListModel(parent)
{
    std::cerr<<"dupa1";

    AddItem(QStringLiteral("Stanisław Czembor"),QStringLiteral("Lidl"),44.88,"05/03/2020");


}

void HistoryListModel::update(const QString &accNum)
{

    History tmp = Bank::accountMap[accNum.toStdString()]->GetHistory();
    auto p = tmp.GetList();
    for(const auto element : *p)
    {
        AddItem(element->GetName(),element->GetDescription(),20,element->GetDate());
    }
    std::cerr<<"jestem w update";
    //AddItem(QStringLiteral("marlenka"),QStringLiteral("Lidl"),QStringLiteral("+44,88"));
}

int HistoryListModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    std::cerr<<"dupa";
    return mList.count();
}

QVariant HistoryListModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    if (row < 0 || row >= mList.count())
        return QVariant();

    // FIXME: Implement me!
    const HistoryItem item = mList.at(row);

    switch (role)
    {
    case NameRole:
        return QVariant(item.name);
    case DescriptionRole:
        return QVariant(item.description);
    case AmountRole:
        return QVariant(item.amount);
    }
    return QVariant();
}

bool HistoryListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    std::cerr<<"danedane";
    if(mList.empty())
        return false;

    HistoryItem item = mList.at(index.row());

    if (data(index, role) != value) {
        // FIXME: Implement me!
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags HistoryListModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable; // FIXME: Implement me!
}

bool HistoryListModel::AddItem(QString name, QString description, double amount, QString date)
{
    emit preItemAppended();
    mList.append({name, description, amount, date});
    emit postItemAppended();
    return true;
}

QHash<int, QByteArray> HistoryListModel::roleNames() const
{
    QHash<int,QByteArray> names;
    names[NameRole] = "name";
    names[DescriptionRole] = "description";
    names[AmountRole] = "amount";
    names[DateRole] = "date";
    return names;
}
