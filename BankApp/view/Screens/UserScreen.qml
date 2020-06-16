import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3
import QtQuick.Controls.Styles 1.4
import components 1.0
import tabs 1.0
Item {
    id: root
    objectName: "userScreen"
    visible: true
    width: parent.width
    height: parent.height
    property var mainStack

    signal logOut()
    onLogOut: {
        mainStack.reset();
    }

    StackView {
        id: contentStack
        anchors.leftMargin: 0
        initialItem: dashboard
        anchors.top: parent.top
        anchors.topMargin: 0
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: menu.right
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

        Dashboard {
            id: dashboard
            height: contentStack.height
            visible: false
            width: contentStack.width
            onForceChangeTab: {
                menu.changeTab(tab);
            }
        }

        Funds {
            id: funds
            height: contentStack.height
            visible: false
            width: contentStack.width
        }

        Payments {
            id: payments
            height: contentStack.height
            visible: false
            width: contentStack.width
        }

        History {
            id: history
            height: contentStack.height
            visible: false
            width: contentStack.width
        }
    }

    ListModel{
        id: menuModel
        ListElement {
            buttonText: "Dashboard"
            buttonIcon: "qrc:/resources/icons/wallet-solid.png"
        }

        ListElement {
            buttonText: "Payments"
            buttonIcon: "qrc:/resources/icons/money-check-alt-solid.png"
        }

        ListElement {
            buttonText: "Funds"
            buttonIcon: "qrc:/resources/icons/piggy-bank-solid.png"
        }

        ListElement {
            buttonText: "History"
            buttonIcon: "qrc:/resources/icons/history-solid.png"
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
        contentArray: [dashboard, payments, funds, history]
        onLogOut: {
            root.logOut();
        }
        onTabChanged: {
            tab.refresh();
        }
    }

}
