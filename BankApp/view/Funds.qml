import QtQuick 2.0
import QtQuick.Controls 2.3

Item {
    id: funds
    visible: true
    width: 700
    height: 700

    FontLoader { id: rubikBold; source: "/resources/fonts/Rubik-Bold.ttf" }
    FontLoader { id: rubikMedium; source: "/resources/fonts/Rubik-Medium.ttf" }
    FontLoader { id: rubikRegular; source: "/resources/fonts/Rubik-Regular.ttf" }

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
            text: qsTr("Funds")
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
            text: qsTr("Check your funds")
            font.pixelSize: 18
            font.family: "Rubik"
        }
    }


}


