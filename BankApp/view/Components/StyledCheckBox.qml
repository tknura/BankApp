import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

CheckBox {
    id: checkBox
    width: parent.width
    height: parent.height
    text: qsTr("Check Box")
    indicator: Rectangle {
        implicitWidth: 25
        implicitHeight: 25
        x: checkBox.leftPadding
        y: parent.height / 2 - height / 2
        radius: 10
        border.color: "#259FC4"
        color: "transparent"

        Rectangle {
            width: 12
            height: 11
            x: 7
            y: 7
            radius: 10
            color: checkBox.down ? "#259FC4" : "transparent"
            visible: checkBox.checked

        }
    }
    contentItem: Text {
        text: checkBox.text
        font.family: "Rubik"
        verticalAlignment: Text.AlignVCenter
        font.weight: Font.Medium
        color: "#259FC4"
        leftPadding: checkBox.indicator.width + checkBox.spacing
    }
}




