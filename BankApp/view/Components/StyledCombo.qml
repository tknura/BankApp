import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

Item {
    id: styledCombo
    visible: true
    width: 640
    height: 80

    property string titleText: "Title"
    property alias model: comboBox.model


    Text {
        id: title
        width: 99
        height: 25
        color: "#393e46"
        text: titleText
        anchors.top: parent.top
        anchors.topMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 22
        font.weight: Font.Medium
        font.family: "Rubik"
        verticalAlignment: Text.AlignVCenter
        font.pixelSize: 20
    }

    Rectangle {
        x: 0
        y: 52
        width: 640
        height: 28
        color: "#F7F7F7"
        border.color: "#F7F7F7"
        border.width: 2
    }

    ComboBox {
        id: comboBox
        objectName: "comboBox"
        leftPadding: 25
        anchors.bottomMargin: 0
        anchors.topMargin: 30
        anchors.bottom: parent.bottom
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.leftMargin: 0
        anchors.right: parent.right
        font.family: "Rubik"
        font.weight: Font.Medium
        background: Rectangle {
            id: background
            color: "#F7F7F7"
            border.color: "#F7F7F7"
            border.width: 2
            radius: 25
        }
    }

}
