import QtQuick 2.0
import QtQuick.Controls 2.3
import "qrc:/view/Components/"

Item {
    id: dashboard
    visible: true
    width: 700
    height: 700

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
            width: 309
            height: 25
            color: "#4c26282a"
            text: qsTr("Welcome back, user")
            anchors.top: parent.top
            anchors.topMargin: 123
            anchors.left: parent.left
            anchors.leftMargin: 70
            font.pixelSize: 18
            font.family: "Rubik"
        }

        Text {
            id: element
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

        Button {
            id: makePaymentButton
            width: 161
            height: 35
            text: qsTr("Make Payment")
            anchors.top: parent.top
            anchors.topMargin: 396
            anchors.left: parent.left
            anchors.leftMargin: 70
            font.family: "Rubik"
            contentItem: Text {
                text: makePaymentButton.text
                font: makePaymentButton.font
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                color: "#259FC4"
            }
            background: Rectangle {
                color: "#A3E7FC"
                border.color: "#A3E7FC"
                border.width: 1
                radius: 25
            }
        }

        Text {
            id: history
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

/*##^##
Designer {
    D{i:1;anchors_height:200;anchors_width:200}
}
##^##*/
