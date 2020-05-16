import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3
import QtQuick.Controls.Styles 1.4
import "qrc:/view/Tabs/"

Rectangle {
    id: root
    objectName: "userScreen"
    visible: true
    width: 1000
    height: 700
    color: "#eeeeee"

    Rectangle {
        id: rectangle
        color: "#ffffff"
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.right: parent.right
        anchors.rightMargin: 750
        border.width: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.top: parent.top
        anchors.topMargin: 0

        Text {
            id: title
            x: 114
            y: 0
            width: 136
            height: 119
            color: "#26282a"
            text: qsTr("Bank\nApp")
            font.weight: Font.Bold
            font.family: "Rubik"
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignLeft
            font.pixelSize: 35
        }

        Column {
            id: menuButtons
            y: 123
            anchors.right: parent.right
            anchors.rightMargin: 0
            anchors.left: parent.left
            anchors.leftMargin: 0
            anchors.top: parent.top
            anchors.topMargin: 123

            RadioButton {
                id: dashboardButton
                x: 0
                y: 125
                width: 250
                height: 59
                ButtonGroup.group: menu
                text: qsTr("Dashboard")
                leftPadding: 20
                padding: 6
                icon.source: "../resources/icons/wallet-solid.png"
                display: AbstractButton.TextBesideIcon
                contentItem: Text {
                    font.weight: Font.Medium
                    horizontalAlignment: Text.AlignHRight
                    verticalAlignment: Text.AlignVCenter
                    color: "#26282a"
                    text: "Dashboard"
                    font.pointSize: 10
                    font.family: "Rubik"
                }
                indicator: Rectangle {
                    anchors.fill: parent
                    visible: dashboardButton.checked
                    color: "#26a3e7fc"
                    border.color: "transparent"
                    Rectangle {
                        id: rectangle5
                        width: 4
                        height: 59
                        color: "#259fc4"
                        radius: 0
                        border.width: 0
                    }

                    Rectangle {
                        id: rectangle4
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

            RadioButton {
                id: paymentsButton
                x: 0
                y: 190
                width: 250
                height: 59
                text: qsTr("Payments")
                leftPadding: 20
                font.pointSize: 10
                ButtonGroup.group: menu
                contentItem: Text {
                    font.weight: Font.Medium
                    horizontalAlignment: Text.AlignHRight
                    verticalAlignment: Text.AlignVCenter
                    color: "#26282a"
                    text: paymentsButton.text
                    font.pointSize: 10
                    font.family: "Rubik"
                }
                indicator: Rectangle {
                    anchors.fill: parent
                    visible: paymentsButton.checked
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
                onCheckedChanged: {
                    contentStack.replace(payments)
                }
            }

            RadioButton {
                id: fundsButton
                x: 0
                y: 255
                width: 250
                height: 59
                text: qsTr("Funds")
                leftPadding: 20
                ButtonGroup.group: menu
                contentItem: Text {
                    font.pointSize: 10
                    font.weight: Font.Medium
                    horizontalAlignment: Text.AlignHRight
                    verticalAlignment: Text.AlignVCenter
                    color: "#26282a"
                    text: fundsButton.text
                    font.family: "Rubik"
                }
                indicator: Rectangle {
                    anchors.fill: parent
                    visible: fundsButton.checked
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
                onCheckedChanged: {
                    contentStack.replace(funds)
                }
            }

            RadioButton {
                id: historyButton
                x: 0
                y: 320
                width: 250
                height: 59
                text: qsTr("History")
                leftPadding: 20
                font.pointSize: 10
                ButtonGroup.group: menu
                contentItem: Text {
                    text: historyButton.text
                    font.pointSize: 10
                    font.weight: Font.Medium
                    horizontalAlignment: Text.AlignHRight
                    verticalAlignment: Text.AlignVCenter
                    color: "#26282a"
                    font.family: "Rubik"
                }
                indicator: Rectangle {
                    anchors.fill: parent
                    visible: historyButton.checked
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
                onCheckedChanged: {
                    contentStack.replace(history)
                }
            }
        }

        Button {
            id: logOutButton
            text: qsTr("Log Out")
            anchors.top: parent.top
            anchors.topMargin: 652
            anchors.right: parent.right
            anchors.rightMargin: 8
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

        Image {
            id: image
            x: 30
            y: 30
            width: 60
            height: 60
            source: "qrc:/resources/icons/landmark-solid.svg"
            sourceSize.width: 60
            sourceSize.height: 60
            fillMode: Image.Stretch
        }

    }

    StackView {
        id: contentStack
        initialItem: dashboard
        anchors.top: parent.top
        anchors.topMargin: 0
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: rectangle.width
        replaceEnter: Transition {
                PropertyAnimation {
                    property: "opacity"
                    from: 0
                    to:1
                    duration: 200
                }
            }
        replaceExit: Transition {
            PropertyAnimation {
                property: "opacity"
                from: 1
                to:0
                duration: 200
            }
        }

        Dashboard {
            id: dashboard
            height: contentStack.height
            visible: false
            width: contentStack.width
        }

        Funds {
            id: funds
            height: contentStack.height
            visible: false
            width: contentStack.width
        }

        Payments {
            id: payments
            height: contentStack.height
            visible: false
            width: contentStack.width
        }

        History {
            id: history

            height: contentStack.height
            visible: false
            width: contentStack.width
        }
    }



    ButtonGroup {
        id: menu
    }
}



/*##^##
Designer {
    D{i:3;anchors_x:0}D{i:24;anchors_height:40;anchors_width:234;anchors_y:652}
}
##^##*/
