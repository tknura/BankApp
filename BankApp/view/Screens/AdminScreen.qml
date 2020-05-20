import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3
import QtQuick.Controls.Styles 1.4
import "qrc:/view/Components/"
import "qrc:/view/Tabs/"

Rectangle {
    id: root
    objectName: "adminScreen"
    visible: true
    width: parent.width
    height: parent.height
    color: "#eeeeee"

    FontLoader { id: rubikBold; source: "/resources/fonts/Rubik-Bold.ttf" }
    FontLoader { id: rubikRegular; source: "/resources/fonts/Rubik-Regular.ttf" }
    FontLoader { id: rubikMedium; source: "/resources/fonts/Rubik-Medium.ttf" }

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
        contentArray: [userAddition, accountAddition, funds, history]
    }
    StackView {
        id: contentStack
        anchors.top: parent.top
        anchors.topMargin: 0
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 250
        initialItem: dashboard
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

        Loader {
            id: funds
            x: 250
            y: 0
            height: contentStack.height
            visible: false
            width: contentStack.width
            source: "qrc:/view/Tabs/Funds.qml"
        }

        Loader {
            id: history
            x: 250
            y: 0
            height: contentStack.height
            visible: false
            width: contentStack.width
            source: "qrc:/view/Tabs/Dashboard.qml"
        }



    }

    ButtonGroup {
        id: menu
    }
}








