import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3
import QtQuick.Controls.Styles 1.4
import components 1.0
import tabs 1.0
Item {
    id: root
    objectName: "adminScreen"
    visible: true
    width: parent.width
    height: parent.height

    signal logOut()

    StackView {
        id: contentStack
        anchors.top: parent.top
        anchors.topMargin: 0
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: menu.right
        anchors.leftMargin: 0
        initialItem: userAddition
        replaceEnter: Transition {
            PropertyAnimation {
                property: "opacity"
                from: 0
                to:1
                duration: 200
            }
        }
        replaceExit: Transition {
            PropertyAnimation {
                property: "opacity"
                from: 1
                to:0
                duration: 200
            }
        }


        UserAddition {
            id: userAddition
            height: contentStack.height
            visible: false
            width: contentStack.width
        }

        AccountAddition {
            id: accountAddition
            height: contentStack.height
            visible: false
            width: contentStack.width
        }

        CardAddition {
            id: cardAddition
            height: contentStack.height
            visible: false
            width: contentStack.width
        }

        FundAddition {
            id: fundAddition
            height: contentStack.height
            visible: false
            width: contentStack.width
        }
    }

    BankMenu {
        id: menu
        width: 300;
        model: menuModel
        anchors.left: parent.left;
        anchors.leftMargin: 0;
        anchors.top: parent.top;
        anchors.topMargin: 0;
        anchors.bottom: parent.bottom;
        anchors.bottomMargin: 0
        screenStack: contentStack
        contentArray: [userAddition, accountAddition, cardAddition, fundAddition]
        onLogOut: {
            logOut();
        }
    }

    ListModel{
        id: menuModel
        ListElement {
            buttonText: "Users"
            buttonIcon: "qrc:/resources/icons/wallet-solid.png"
        }

        ListElement {
            buttonText: "Accounts"
            buttonIcon: "qrc:/resources/icons/money-check-alt-solid.png"
        }

        ListElement {
            buttonText: "Cards"
            buttonIcon: "qrc:/resources/icons/piggy-bank-solid.png"
         }

        ListElement {
            buttonText: "Funds"
            buttonIcon: "qrc:/resources/icons/history-solid.png"
        }
    }


}








