import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

Window {
    id: window
    minimumWidth: 700
    minimumHeight: 650
    visible: true
    width: 1000
    height: 700
    color: "#eeeeee"
    title: "Login"

    Text {
        id: title
        height: 190
        color: "#393e46"
        text: qsTr("BankApp")
        anchors.right: parent.right
        anchors.rightMargin: 291
        anchors.left: parent.left
        anchors.leftMargin: 292
        anchors.top: parent.top
        anchors.topMargin: 142
        font.family: "Arial"
        font.weight: Font.Bold
        font.bold: false
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        wrapMode: Text.NoWrap
        font.pixelSize: 60
    }

    Button {
        id: proceedButton
        x: 651
        width: 136
        height: 40
        anchors.right: parent.right
        anchors.rightMargin: 213
        autoRepeat: false
        flat: false
        highlighted: false
        anchors.top: parent.top
        anchors.topMargin: 530
        font.family: "Arial"
        checkable: false
        display: AbstractButton.TextOnly
        text: qsTr("Proceed")
        contentItem: Text {
            text: proceedButton.text
            font: proceedButton.font
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

    GroupBox {
        id: loginBox
        height: 79
        anchors.top: parent.top
        anchors.topMargin: 338
        anchors.left: parent.left
        anchors.leftMargin: 223
        anchors.right: parent.right
        anchors.rightMargin: 213
        background: Rectangle {
                color: "transparent"
                border.color: "transparent"
            }

        Text {
            id: login
            x: -12
            y: -12
            width: 99
            height: 25
            color: "#393e46"
            text: qsTr("Login")
            font.family: "Arial"
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 20
        }

        TextField {
            id: loginField
            leftPadding: 25
            padding: 6
            font.letterSpacing: 0
            font.wordSpacing: 0
            anchors.top: parent.top
            anchors.topMargin: 19
            anchors.bottom: parent.bottom
            anchors.bottomMargin: -12
            anchors.left: parent.left
            anchors.leftMargin: -12
            anchors.right: parent.right
            anchors.rightMargin: -12
            font.family: "Arial"
            placeholderText: "login"
            horizontalAlignment: Text.AlignLeft
            background: Rectangle {
                        color: "#F7F7F7"
                        border.color: "#F7F7F7"
                        border.width: 1
                        radius: 25
                    }
        }

    }

    GroupBox {
        id: passwordBox
        x: -9
        y: -8
        height: 79
        anchors.topMargin: 433
        anchors.rightMargin: 213
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.leftMargin: 223
        anchors.right: parent.right
        background: Rectangle {
                color: "transparent"
                border.color: "transparent"
            }

        Text {
            id: password
            x: -12
            y: -12
            width: 99
            height: 25
            color: "#393e46"
            text: qsTr("Password")
            font.family: "Arial"
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 20
        }

        TextField {
            id: passwordField
            leftPadding: 25
            anchors.bottomMargin: -12
            font.family: "Arial"
            anchors.topMargin: 19
            anchors.bottom: parent.bottom
            anchors.rightMargin: -12
            anchors.left: parent.left
            anchors.top: parent.top
            horizontalAlignment: Text.AlignLeft
            anchors.leftMargin: -12
            anchors.right: parent.right
            placeholderText: "password"
            background: Rectangle {
                        color: "#F7F7F7"
                        border.color: "#F7F7F7"
                        border.width: 1
                        radius: 25
                    }
        }
    }

}

/*##^##
Designer {
    D{i:1;anchors_height:190;anchors_width:417;anchors_x:292;anchors_y:134}D{i:8;anchors_height:48;anchors_width:566;anchors_x:-14;anchors_y:19}
D{i:5;anchors_width:564;anchors_x:223;anchors_y:338}D{i:13;anchors_height:48;anchors_width:566;anchors_x:"-14";anchors_y:19}
D{i:10;anchors_width:564;anchors_x:223;anchors_y:338}
}
##^##*/
