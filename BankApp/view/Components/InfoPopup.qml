import QtQuick 2.0
import QtQuick.Controls 2.13

Item {
    width: 400
    height: 200

    property alias title: title.text
    property alias titleColor: title.color
    property alias description: desc.text
    property var buttonOnClicked

    Rectangle {
        id: rectangle
        color: "#ffffff"
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        anchors.fill: parent

        Text {
            id: title
            color: "#26282a"
            text: qsTr("Title")
            anchors.left: parent.left
            anchors.leftMargin: 19
            anchors.top: parent.top
            anchors.topMargin: 8
            font.family: "Rubik"
            font.weight: Font.Bold
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignLeft
            font.pixelSize: 35
        }

        Button {
            id: button
            x: 268
            y: 156
            width: 108
            height: 36
            text: qsTr("OK")
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 8
            anchors.right: parent.right
            anchors.rightMargin: 24
            font.family: "Rubik"
            display: AbstractButton.TextOnly
            contentItem: Text {
                text: button.text
                font: button.font
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                color: "#259FC4"
            }
            background: Rectangle {
                color: button.pressed ? "#75b4c5" : button.hovered ? "#7cd2ed" : "#A3E7FC"
                radius: 25
            }
            onClicked: buttonOnClicked
        }

        Text {
            id: desc
            height: 110
            color: "#7b7b7b"
            text: qsTr("Description")
            wrapMode: Text.WordWrap
            anchors.right: parent.right
            anchors.rightMargin: 24
            anchors.top: parent.top
            anchors.topMargin: 47
            anchors.left: parent.left
            anchors.leftMargin: 24
            font.family: "Rubik"
            font.pixelSize: 16
        }

    }

}


