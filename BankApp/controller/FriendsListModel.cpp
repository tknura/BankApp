#include "FriendsListModel.h"


FriendsListModel::FriendsListModel(QObject *parent) : QAbstractListModel(parent)
{
    update();
}

void FriendsListModel::update()
{
    beginResetModel();
    auto p = Bank::GetLoggedUser<User>()->GetFriendsList();
    for(const auto &element : *p)
    {
        AddItem(QString::fromStdString(element->GetName()),
                QString::fromStdString(element->GetAccNumer()),
                QString::fromStdString(element->GetAddress()));
    }
    endResetModel();
}

void FriendsListModel::clear()
{

    beginResetModel();

    for (int j = 0; j< 5; j++)
    {
        for(int i = 0; i< mList.size(); ++i)
        {
            preItemRemoved(i);

            mList.removeAt(i);

            postItemRemoved();
        }
    }

    endResetModel();
}

int FriendsListModel::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid())
        return 0;
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    return mList.count();
}

QVariant FriendsListModel::data(const QModelIndex &index, int role) const
{
    int row = index.row();
    if (row < 0 || row >= mList.count())
        return QVariant();

    // FIXME: Implement me!
    const FriendItem item = mList.at(row);

    switch (role)
    {
    case NameRole:
        return QVariant(item.name);
    case AccNumRole:
        return QVariant(item.accNum);
    case AddressRole:
        return QVariant(item.address);
    }
    return QVariant();
}

bool FriendsListModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(mList.empty())
        return false;

    FriendItem item = mList.at(index.row());

    if (data(index, role) != value) {
        // FIXME: Implement me!
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags FriendsListModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable; // FIXME: Implement me!
}

QHash<int, QByteArray> FriendsListModel::roleNames() const
{
    QHash<int,QByteArray> names;
    names[NameRole] = "name";
    names[AccNumRole] = "accNum";
    names[AddressRole] = "address";
    return names;
}

bool FriendsListModel::AddItem(QString name, QString accNum, QString address)
{
    emit preItemAppended();
    mList.append({name, accNum, address});
    emit postItemAppended();
    return true;
}

