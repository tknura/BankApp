import QtQuick 2.0
import QtQuick.Controls 2.3

Item {
    id: dashboard
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
            text: qsTr("Dashboard")
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
            text: qsTr("Welcome back, user")
            font.pixelSize: 18
            font.family: "Rubik"
        }

        Text {
            id: element
            x: 70
            y: 177
            width: 247
            height: 57
            text: qsTr("Accounts")
            font.weight: Font.Medium
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 30
            font.family: "Rubik"
        }

        Button {
            id: makePaymentButton
            x: 70
            y: 396
            width: 161
            height: 35
            text: qsTr("Make Payment")
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
            id: element1
            x: 70
            y: 455
            width: 247
            height: 57
            text: qsTr("Today")
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
