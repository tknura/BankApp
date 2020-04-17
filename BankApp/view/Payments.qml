import QtQuick 2.0
import QtQuick.Controls 2.3

Item {
    state: Dashboard
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
            id: element1
            x: 294
            y: 313
            width: 113
            height: 75
            text: qsTr("Payments")
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 12
        }
    }


}

/*##^##
Designer {
    D{i:1;anchors_height:200;anchors_width:200}
}
##^##*/
