import QtQuick 2.0
import QtQuick.Controls 2.3
import components 1.0

Item {
    id: payments
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
            x: 70
            y: 50
            width: 328
            height: 75
            color: "#26282a"
            text: qsTr("Payments")
            font.weight: Font.Bold
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignLeft
            font.pixelSize: 60
            font.family: "Rubik"
        }

        Text {
            id: desc
            x: 70
            y: 123
            width: 309
            height: 25
            color: "#4c26282a"
            text: qsTr("Make a new payment")
            font.pixelSize: 18
            font.family: "Rubik"
        }
    }
}


