import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

Window {
    id: main
    minimumWidth: 700
    minimumHeight: 400
    visible: true
    width: 1000
    height: 700
    color: "#eeeeee"
    title: "main"

    FontLoader { id: rubikBold; source: "/resources/fonts/Rubik-Bold.ttf" }
    FontLoader { id: rubikMedium; source: "/resources/fonts/Rubik-Medium.ttf" }
    FontLoader { id: rubikRegular; source: "/resources/fonts/Rubik-Regular.ttf" }

    GroupBox {
        background: Rectangle {
            color: "transparent"
            border.color: "transparent"
        }
        id: tabs
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 250
        anchors.top: parent.top
        anchors.topMargin: 0
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0

        Loader {
            id: dashboard
            visible: true
            anchors.fill: parent
            source: "Dashboard.qml"
        }

        Loader {
            id: payments
            visible: false
            anchors.fill: parent
            source: "Payments.qml"
        }

        Loader {
            id: funds
            visible: false
            anchors.fill: parent
            source: "Funds.qml"
        }

        Loader {
            id: history
            visible: false
            anchors.fill: parent
            source: "History.qml"
        }
    }

    Rectangle {
        id: rectangle
        width: 250
        color: "#ffffff"
        border.width: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.top: parent.top
        anchors.topMargin: 0
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0



        Text {
            id: title
            x: 0
            y: 0
            width: 250
            height: 119
            color: "#26282a"
            text: qsTr("Bank App")
            font.weight: Font.Bold
            font.family: "Rubik"
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 30
        }

        Column {
            id: menuButtons
            x: 0
            y: 123
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
                icon.source: "../resources/icons/wallet-solid.png"
                display: AbstractButton.TextBesideIcon
                contentItem: Text {
                    font.weight: Font.Medium
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    color: "#26282a"
                    text: dashboardButton.text
                    font.pointSize: 10
                    font.family: "Rubik"
                }
                checked: true
                onCheckedChanged: {
                    dashboard.visible = true
                    payments.visible = false
                    history.visible = false
                    funds.visible = false
                }
            }

            RadioButton {
                id: paymentsButton
                x: 0
                y: 190
                width: 250
                height: 59
                text: qsTr("Payments")
                font.pointSize: 10
                ButtonGroup.group: menu
                contentItem: Text {
                    font.weight: Font.Medium
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    color: "#26282a"
                    text: paymentsButton.text
                    font.pointSize: 10
                    font.family: "Rubik"
                }
                onCheckedChanged: {
                    dashboard.visible = false
                    payments.visible = true
                    history.visible = false
                    funds.visible = false
                }
            }

            RadioButton {
                id: fundsButton
                x: 0
                y: 255
                width: 250
                height: 59
                text: qsTr("Funds")
                ButtonGroup.group: menu
                contentItem: Text {
                    font.pointSize: 10
                    font.weight: Font.Medium
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    color: "#26282a"
                    text: fundsButton.text
                    font.family: "Rubik"
                }
                onCheckedChanged: {
                    dashboard.visible = false
                    payments.visible = false
                    history.visible = false
                    funds.visible = true
                }
            }

            RadioButton {
                id: historyButton
                x: 0
                y: 320
                width: 250
                height: 59
                text: qsTr("History")
                font.pointSize: 10
                ButtonGroup.group: menu
                contentItem: Text {
                    text: historyButton.text
                    font.pointSize: 10
                    font.weight: Font.Medium
                    horizontalAlignment: Text.AlignHCenter
                    verticalAlignment: Text.AlignVCenter
                    color: "#26282a"
                    font.family: "Rubik"
                }
                onCheckedChanged: {
                    dashboard.visible = false
                    payments.visible = false
                    history.visible = true
                    funds.visible = false
                }
            }
        }

        Button {
            id: logOutButton
            y: 652
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
    ButtonGroup {
        id: menu
    }


}



/*##^##
Designer {
    D{i:5;invisible:true}D{i:4;invisible:true}D{i:21;anchors_x:8}
}
##^##*/
