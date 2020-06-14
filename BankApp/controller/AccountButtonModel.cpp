#include "AccountButtonModel.h"
#include "model/Bank.h"

AccountButtonModel::AccountButtonModel(QObject *parent)
    : QAbstractListModel(parent)
{
    update();
}

void AccountButtonModel::update() {
    beginResetModel();
    std::string type = "", num, balance, currency, isDisabled;
    std::cerr<<"\nzalogowany user:"<<Bank::GetLoggedUser<User>()->GetID();
    for(auto it = Bank::GetLoggedUser<User>()->GetAccountList()->begin();
         it != Bank::GetLoggedUser<User>()->GetAccountList()->end(); ++it){
        auto acc = Bank::accountMap.find(it->data());
        std::cerr<<"\nid superwizora:"<<acc->second->GetSupervisorId();
        //type = acc->second->GetType();
        AddItem("Personal",QString::fromStdString(it->data()),
                acc->second->GetBalance());
    }
    endResetModel();
}

void AccountButtonModel::clear() {
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

int AccountButtonModel::rowCount(const QModelIndex &parent) const {
    return mList.count();
}

QVariant AccountButtonModel::data(const QModelIndex &index, int role) const {
    int row = index.row();
    if (row < 0 || row >= mList.count())
        return QVariant();

    const AccountButtonInfo item = mList.at(row);
    switch (role)
    {
    case TypeRole:
        return QVariant(item.type);
    case NumberRole:
        return QVariant(item.number);
    case AmountRole:
        return QVariant(item.amount);
    case CurrencyRole:
        return QVariant(item.currrency);
    case DisabledRole:
        return QVariant(item.disabled);
    }
    return QVariant();
}

bool AccountButtonModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    if(mList.empty())
        return false;

    AccountButtonInfo item = mList.at(index.row());

    if (data(index, role) != value) {
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags AccountButtonModel::flags(const QModelIndex &index) const {
    if (!index.isValid())
        return Qt::NoItemFlags;

    return Qt::ItemIsEditable;
}

QHash<int, QByteArray> AccountButtonModel::roleNames() const {
    QHash<int,QByteArray> names;
    names[TypeRole] = "type";
    names[NumberRole] = "number";
    names[AmountRole] = "amount";
    names[CurrencyRole] = "currency";
    names[DisabledRole] = "disabled";
    return names;
}

bool AccountButtonModel::AddItem(QString type, QString number, double amount,
                                 QString curr, bool disabled) {
    emit preItemAppended();
    mList.append({type, number, amount, curr, disabled});
    emit postItemAppended();
    return true;
}
