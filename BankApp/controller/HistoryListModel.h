#ifndef HISTORYLISTMODEL_H
#define HISTORYLISTMODEL_H

#include <QAbstractListModel>

#include "HistoryList.h"

class HistoryList;

class HistoryListModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(HistoryList *list READ list WRITE setList);

public:
    explicit HistoryListModel(QObject *parent = nullptr);

    enum
    {
        NameRole = Qt::UserRole,
        DescriptionRole,
        AmountRole
    };


    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    virtual QHash<int, QByteArray> roleNames() const override;

    HistoryList *list() const;
    void setList(HistoryList *list);

   // QString GetItem(){mList->GetItem();}


private:
    HistoryList *mList;
};

#endif // HISTORYLISTMODEL_H
