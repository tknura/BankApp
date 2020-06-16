import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3
import components 1.0

Rectangle {
    id: loginScreen
    objectName: "loginScreen"
    width: 1000
    height: 700
    color: "#eeeeee"

    property var screenParent;

    function clear() {
        passwordInput.clear();
        loginInput.clear();
    }

    function loggingPassed() {
        loginDataBoxes.state = "NORMAL"
    }

    function loggingFailed() {
        loginDataBoxes.state = "FAILED"
    }

    function loadUserScreen() {
        screenParent.replace(["qrc:/screens/UserScreen.qml",
                              {width: loginScreen.width, height: loginScreen.height, mainStack: screenParent}])
    }

    function loadAdminScreen() {
        screenParent.replace(["qrc:/screens/AdminScreen.qml",
                             {width: loginScreen.width, height: loginScreen.height, mainStack: screenParent}])
    }

    signal inputValues(string login, string password)

    GroupBox {
        id: loginDataBoxes
        width: 485
        height: 207
        anchors.verticalCenterOffset: 36
        anchors.horizontalCenterOffset: 1
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.verticalCenter: parent.verticalCenter
        background: Rectangle {
            color: "transparent"
            border.color: "transparent"
        }

        states: [
            State {
                name: "FAILED"
                PropertyChanges { target: passwordInput; state: "FAILED" }
                PropertyChanges { target: loginInput; state: "FAILED" }
                PropertyChanges { target: failedText; visible: true}
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
            isHashed: true
            titleText: "Password"
            placeholder: "password"
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
            titleText: "Login/E-mail"
            placeholder: "login"
        }
        Text {
            id: failedText
            visible: false
            x: 23
            y: 174
            width: 124
            height: 15
            color: "#ed2939"
            text: qsTr("Invalid login/password")
            font.pixelSize: 12
        }
    }

    Text {
        id: title
        x: 373
        y: 86
        height: 190
        color: "#393e46"
        text: qsTr("Bank App")
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.bottom: loginDataBoxes.top
        anchors.bottomMargin: 6
        font.family: "Rubik"
        font.weight: Font.Bold
        font.bold: false
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignHCenter
        wrapMode: Text.NoWrap
        font.pixelSize: 60
    }

    PushButton {
        id: proceedButton
        objectName: "proceedButton"
        text: "Proceed"
        anchors.horizontalCenterOffset: 157
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: loginDataBoxes.bottom
        anchors.bottomMargin: 111
        anchors.leftMargin: 574
        anchors.topMargin: 18
        x: 636
        width: 136
        height: 40
        onClicked: {
            inputValues(loginInput.inputText, passwordInput.inputText)
        }
    }
}
