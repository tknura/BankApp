#ifndef FRIENDSLISTMODEL_H
#define FRIENDSLISTMODEL_H

#include <QObject>
#include <QAbstractListModel>

#include "model/Bank.h"
#include "model/User.h"
#include "model/PaymentRetriever.h"
struct FriendItem
{
    QString name;
    QString accNum;
    QString address;
};


class FriendsListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit FriendsListModel(QObject *parent = nullptr);
    enum
    {
        NameRole = Qt::UserRole,
        AccNumRole,
        AddressRole
    };

    //method able to be called from QML
    Q_INVOKABLE void update();
    Q_INVOKABLE void clear();


    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    virtual QHash<int, QByteArray> roleNames() const override;

    bool AddItem(QString name = "unknown", QString accNum = "0000000000000000", QString address = "ul.       ");

signals:
    void preItemAppended();
    void postItemAppended();

    void preItemRemoved(int index);
    void postItemRemoved();

private:
    QList<FriendItem> mList;
    int m_count;
};

#endif // FRIENDSLISTMODEL_H
