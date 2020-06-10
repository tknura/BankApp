#ifndef HISTORYLISTMODEL_H
#define HISTORYLISTMODEL_H

#include <QAbstractListModel>

//#include "HistoryList.h"

struct HistoryItem
{
    QString name;
    QString description;
    QString amount;
    QString date;
};

class HistoryListModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit HistoryListModel(QObject *parent = 0);

    enum
    {
        NameRole = Qt::UserRole,
        DescriptionRole,
        AmountRole,
        DateRole
    };


    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;

    virtual QHash<int, QByteArray> roleNames() const override;

    bool AddItem(QString name = "default", QString description = "default", QString amount = "+00,00",QString date = "00/00/0000");

signals:
    void preItemAppended();
    void postItemAppended();

private:
    QList<HistoryItem> mList;
    int m_count;
};

#endif // HISTORYLISTMODEL_H
