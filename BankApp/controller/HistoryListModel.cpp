#include "HistoryListModel.h"
#include "HistoryList.h"
#include <iostream>

HistoryListModel::HistoryListModel(QObject *parent)
    : QAbstractListModel(parent),
      mList(nullptr)
{
    std::cerr<<"dupa1";
}

int HistoryListModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    std::cerr<<"dupa";
    if (!mList)
        return 0;

    // FIXME: Implement me!
    return mList->items().size();
}

QVariant HistoryListModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() or !mList)
        return QVariant();

    // FIXME: Implement me!
    const HistoryItem item = mList->items().at(index.row());

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
    if(!mList)
        return false;

    HistoryItem item = mList->items().at(index.row());


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

QHash<int, QByteArray> HistoryListModel::roleNames() const
{
    QHash<int,QByteArray> names;
    names[NameRole] = "name";
    names[DescriptionRole] = "description";
    names[AmountRole] = "amount";
    return names;
}

HistoryList *HistoryListModel::list() const
{
    return mList;
}

void HistoryListModel::setList(HistoryList *list)
{
   std::cerr<<"ruchanie";
   beginResetModel();

    if(mList)
        mList->disconnect(this);

    mList = list;

    if(mList)
    {
        connect(mList, &HistoryList::preItemAppended, this, [=]()
        {
            const int index = mList->items().size();
            beginInsertRows(QModelIndex(),index,index);
        });
        connect(mList, &HistoryList::postItemAppended, this, [=]()
        {
            endInsertRows();
        });
    }
    endResetModel();
}
