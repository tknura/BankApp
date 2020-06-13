#include "AccountButtonModel.h"
#include "model/Bank.h"

AccountButtonModel::AccountButtonModel(QObject *parent)
    : QAbstractListModel(parent)
{
    std::string type = "", num, balance, currency, isDisabled;
    for(auto it = Bank::GetLoggedUser<User>()->GetAccountList()->begin();
         it != Bank::GetLoggedUser<User>()->GetAccountList()->end(); ++it){
        auto acc = Bank::accountMap.find(it->data());
        //type = acc->second->GetType();
        num = it->data();
        balance = std::to_string(acc->second->GetBalance());
        currency = "PLN";
    }
}

void AccountButtonModel::update() {

}

void AccountButtonModel::clear() {

}

int AccountButtonModel::rowCount(const QModelIndex &parent) const {

}

QVariant AccountButtonModel::data(const QModelIndex &index, int role) const {

}

bool AccountButtonModel::setData(const QModelIndex &index, const QVariant &value, int role) {

}

Qt::ItemFlags AccountButtonModel::flags(const QModelIndex &index) const {

}

QHash<int, QByteArray> AccountButtonModel::roleNames() const {

}
