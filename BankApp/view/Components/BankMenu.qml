import QtQuick 2.0
import QtQuick.Controls 2.13
import QtGraphicalEffects 1.14

Item {
    width: 250

    property list<string> values;

    ListModel {
        id: menuModel
        ListElement {
            buttonText: "Dashboard"
            buttonIcon: "../resources/icons/wallet-solid.png"
        }
    }

    Component {
        id: button
        RadioButton {
            id: dashboardButton
            x: 0
            y: 125
            width: 250
            height: 59
            ButtonGroup.group: menu
            leftPadding: 20
            padding: 6
            icon.source: buttonIcon
            display: AbstractButton.TextBesideIcon

            contentItem: Text {
                font.weight: Font.Medium
                horizontalAlignment: Text.AlignHRight
                verticalAlignment: Text.AlignVCenter
                color: "#26282a"
                text: buttonText
                font.pointSize: 10
                font.family: "Rubik"
            }

            indicator: Rectangle {
                anchors.fill: parent
                visible: dashboardButton.checked
                color: "#26a3e7fc"
                border.color: "transparent"
                Rectangle {
                    width: 4
                    height: 59
                    color: "#259fc4"
                    radius: 0
                    border.width: 0
                }

                Rectangle {
                    width: 10
                    color: "#259fc4"
                    radius: 5
                    anchors.left: parent.left
                    anchors.leftMargin: 0
                    anchors.bottom: parent.bottom
                    anchors.bottomMargin: 0
                    anchors.top: parent.top
                    anchors.topMargin: 0
                }
            }
            checked: true
            onCheckedChanged: {
                contentStack.replace(dashboard)
            }
        }
    }

    Rectangle {
        id: background
        color: "#ffffff"
        anchors.fill: parent
        border.width: 0


        Column {
            id: menuButtons
            x: 0
            y: 123
            anchors.top: parent.top
            anchors.topMargin: 123
        }

        GroupBox {
            id: titleGroup
            height: 123
            anchors.left: parent.left
            anchors.leftMargin: 0
            anchors.top: parent.top
            anchors.topMargin: 0
            anchors.right: parent.right
            anchors.rightMargin: 0
            background: Rectangle {
                color: "transparent"
                border.color: "transparent"
            }

            Text {
                id: title
                y: -12
                height: 123
                color: "#26282a"
                text: qsTr("Bank\nApp")
                anchors.left: parent.left
                anchors.leftMargin: 109
                anchors.right: parent.right
                anchors.rightMargin: -12
                font.weight: Font.Bold
                font.family: "Rubik"
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignLeft
                font.pixelSize: 35
            }

            Image {
                id: titleIcon
                width: 77
                height: 83
                anchors.top: parent.top
                anchors.topMargin: 8
                anchors.left: parent.left
                anchors.leftMargin: 14
                source: "qrc:/resources/icons/landmark-solid.svg"
                sourceSize.width: 60
                sourceSize.height: 60
                fillMode: Image.PreserveAspectFit
            }
            ColorOverlay {
                anchors.fill: titleIcon
                source: titleIcon
                color: "#393e46"
            }

        }

        Button {
            id: logOutButton
            x: 8
            y: 75
            width: 234
            height: 40
            text: qsTr("Log Out")
            anchors.left: parent.left
            anchors.leftMargin: 8
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 8
            font.weight: Font.Medium
            display: AbstractButton.TextOnly
            background: Rectangle {
                color: "transparent"
            }
            contentItem: Text {
                color: "#4c26282a"
                text: logOutButton.text
                font.pointSize: 10
                font.weight: Font.Medium
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.family: "Rubik"
            }
        }




    }
}


