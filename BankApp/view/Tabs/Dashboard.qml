import QtQuick 2.0
import QtQuick.Controls 2.3
import "qrc:/view/Components/"

Item {
    id: dashboard
    visible: true
    width: 700
    height: 700

    signal refresh(string accNumber)

    onRefresh: {
        console.log(accNumber);
    }

    Component.onCompleted:  {
        accountsList.addButton("Regular", "1234 1234 1234 1234", "999,99", "PLN", false);
        accountsList.addButton("Family", "4321 4321 4321 4321", "999,99", "PLN", false);
        accountsList.addButton("Currency", "1234 1234 1234 1234", "999,99", "PLN", true);
    }

    Rectangle {
        id: background
        color: "#eeeeee"
        border.width: 0
        border.color: "#eeeeee"
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.top: parent.top
        anchors.topMargin: 0
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0


        Text {
            id: title
            width: 328
            height: 75
            color: "#26282a"
            text: qsTr("Dashboard")
            anchors.left: parent.left
            anchors.leftMargin: 70
            anchors.top: parent.top
            anchors.topMargin: 50
            font.weight: Font.Bold
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignLeft
            font.pixelSize: 60
            font.family: "Rubik"
        }

        Text {
            id: desc
            width: 328
            height: 25
            color: "#4c26282a"
            text: qsTr("Welcome back, user")
            anchors.top: title.bottom
            anchors.topMargin: 0
            anchors.left: parent.left
            anchors.leftMargin: 70
            font.pixelSize: 18
            font.family: "Rubik"
        }

        Text {
            id: accounts
            width: 247
            height: 57
            text: qsTr("Accounts")
            anchors.top: parent.top
            anchors.topMargin: 177
            anchors.left: parent.left
            anchors.leftMargin: 70
            font.weight: Font.Medium
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 30
            font.family: "Rubik"
        }

        AccountButtonList {
            id: accountsList
            objectName: "accountsList"
            height: 160
            anchors.right: parent.right
            anchors.rightMargin: 48
            anchors.left: parent.left
            anchors.leftMargin: 70
            anchors.top: accounts.bottom
            anchors.topMargin: 6
            itemToRefresh: dashboard
        }

        PushButton {
            id: paymentButton
            width: 161
            height: 35
            text: qsTr("Make Payment")
            anchors.top: parent.top
            anchors.topMargin: 406
            anchors.left: parent.left
            anchors.leftMargin: 70          
        }

        Text {
            id: historyTitle
            width: 247
            height: 57
            text: qsTr("Today")
            anchors.top: parent.top
            anchors.topMargin: 455
            anchors.left: parent.left
            anchors.leftMargin: 70
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 30
            font.family: "Rubik"
            font.weight: Font.Medium
        }
    }
}


