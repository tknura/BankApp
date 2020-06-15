import QtQuick 2.0
import QtQuick.Controls 2.1

Button {
    width: 120
    height: 30
    id: pushButton
    objectName: "pushButton"
    font.family: "Rubik"
    display: AbstractButton.TextOnly
    text: qsTr("Text")
    contentItem: Text {
        text: pushButton.text
        font: pushButton.font
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        color: "#259FC4"
    }
    background: Rectangle {
        color: pushButton.pressed ? "#b9edfe" : pushButton.hovered ? "#b1ebfd" : "#A3E7FC"
        radius: 25
    }
}


