import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3
import QtQuick.Controls.Styles 1.4
import "qrc:/view/Tabs/"
import "qrc:/view/Components/"

Rectangle {
    id: root
    objectName: "userScreen"
    visible: true
    width: parent.width
    height: parent.height
    color: "#eeeeee"


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
    }

    StackView {
        id: contentStack
        initialItem: dashboard
        anchors.top: parent.top
        anchors.topMargin: 0
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: menu.width
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
}
