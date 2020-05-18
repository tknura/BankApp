import QtQuick 2.0
import QtQuick.Controls 2.13

Popup {
    id: root
    width: 400
    height: 200
    property alias title: title.text
    property alias titleColor: title.color
    property alias description: desc.text

    Rectangle {
        id: rectangle
        color: "#ffffff"
        anchors.fill: parent
        radius: 25
        opacity: 0.8
    }

    background:
        Rectangle {
        color: "transparent"
        border.color: "transparent"
        opacity: rectangle.opacity
    }

    Text {
        id: desc
        x: 24
        y: 47
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

    Text {
        id: title
        x: 19
        y: 8
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

}


