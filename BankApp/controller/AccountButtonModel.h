#ifndef ACCOUNTBUTTONMODEL_H
#define ACCOUNTBUTTONMODEL_H
#include <QAbstractListModel>

struct AccountButtonInfo {
    QString typeText;
    QString accNum;
    QString amountText;
    QString currText;
    bool isDisabled;
};

class AccountButtonModel : public QAbstractListModel
{
    Q_OBJECT

public:
    explicit AccountButtonModel(QObject *parent = 0);
    enum
    {
        TypeRole,
        NumberRole,
        AmountRole,
        CurrencyRole,
        DisabledRole
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

    bool AddItem(QString name = "default", QString description = "default", double amount = 00.00,QString date = "00/00/0000");

signals:
    void preItemAppended();
    void postItemAppended();

    void preItemRemoved(int index);
    void postItemRemoved();

private:
    QList<AccountButtonInfo> mList;
    int m_count;
};

#endif // ACCOUNTBUTTONMODEL_H
