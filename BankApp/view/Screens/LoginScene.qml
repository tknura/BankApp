import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3
import "qrc:/view/Components/"
Window {
    id: window

    minimumWidth: 700
    minimumHeight: 650
    visible: true
    width: 1000
    height: 700
    color: "#eeeeee"
    title: "Login"
    FontLoader { id: rubikBold; source: "/resources/fonts/Rubik-Bold.ttf" }
    FontLoader { id: rubikRegular; source: "/resources/fonts/Rubik-Regular.ttf" }
    FontLoader { id: rubikMedium; source: "/resources/fonts/Rubik-Medium.ttf" }

    function loggingPassed() {
        loginDataBoxes.state = "NORMAL"
    }

    function loggingFailed() {
        loginDataBoxes.state = "FAILED"
    }

    GroupBox {
        id: loginDataBoxes
        height: 207
        anchors.right: parent.right
        anchors.rightMargin: 211
        anchors.left: parent.left
        anchors.leftMargin: 211
        anchors.top: parent.top
        anchors.topMargin: 299
        background: Rectangle {
            color: "transparent"
            border.color: "transparent"
        }

        states: [
            State {
                name: "FAILED"
                PropertyChanges { target: passwordInput; state: "FAILED" }
                PropertyChanges { target: loginInput; state: "FAILED" }
            }
        ]

        StyledInput {
            id: passwordInput
            height: 80
            anchors.top: parent.top
            anchors.topMargin: 88
            anchors.left: parent.left
            anchors.leftMargin: 4
            anchors.right: parent.right
            anchors.rightMargin: 4
            Component.onCompleted: {
                passwordInput.setHashed(true)
                passwordInput.setPlaceholderText("password")
                passwordInput.setTitle("Password")
            }
        }

        StyledInput {
            id: loginInput
            height: 80
            anchors.top: parent.top
            anchors.topMargin: 2
            anchors.left: parent.left
            anchors.leftMargin: 4
            anchors.right: parent.right
            anchors.rightMargin: 4
            Component.onCompleted: {
                loginInput.setPlaceholderText("login")
                loginInput.setTitle("Login/E-mail")
            }
        }

        }

    Text {
        id: title
        height: 190
        color: "#393e46"
        text: qsTr("Bank App")
        font.family: "Rubik"
        anchors.right: parent.right
        anchors.rightMargin: 291
        anchors.left: parent.left
        anchors.leftMargin: 293
        anchors.top: parent.top
        anchors.topMargin: 142
        font.weight: Font.Bold
        font.bold: false
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        wrapMode: Text.NoWrap
        font.pixelSize: 60
    }

    Button {
        id: proceedButton
        objectName: "proceedButton"
        x: 651
        width: 136
        height: 40
        anchors.right: parent.right
        anchors.rightMargin: 213
        anchors.top: parent.top
        anchors.topMargin: 530
        font.family: "Rubik"
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
            color: proceedButton.pressed ? "#75b4c5" : proceedButton.hovered ? "#7cd2ed" : "#A3E7FC"
            radius: 25
        }
    }



}




