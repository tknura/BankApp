import QtQuick 2.0
import QtQuick.Controls 2.13

Popup {
    id: root
    width: 400
    height: 100
    modal: true
    focus: true
    closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutside
    property alias color: message.color
    property alias message: message.text

    background: Rectangle {
        id: rectangle
        color: "#7b7b7b"
        anchors.fill: parent
        radius: 25
        opacity: 0.8
        border.color: "transparent"

        Button {
            id: button
            x: 371
            width: 23
            height: 21
            text: qsTr("X")
            contentItem: Text {
                text: button.text
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.pointSize: 12
                font.family: "Rubik"
                color: message.color
            }
            anchors.right: parent.right
            anchors.rightMargin: 6
            anchors.top: parent.top
            anchors.topMargin: 4
            background: Rectangle {
                color: "transparent"
            }
            onClicked: root.close()
        }
    }

    contentItem: Text {
        id: message
        x: 24
        y: 47
        color: "#eeeeee"
        text: qsTr("Description")
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 20
        wrapMode: Text.WordWrap
        anchors.right: parent.right
        anchors.rightMargin: 20
        anchors.top: parent.top
        anchors.topMargin: 20
        anchors.left: parent.left
        anchors.leftMargin: 20
        font.family: "Rubik"
        font.pixelSize: 16
    }


}




