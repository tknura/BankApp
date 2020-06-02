import QtQuick 2.0
import QtQuick.Controls 2.3
import components 1.0

Item {
    id: element
    objectName: "userAddition"
    visible: true
    width: 700
    height: 700

    signal userAddition(string login, string password, string mail)

    function clearInputs() {
        for(var i = 0; i < inputs.children.length; ++i) {
            if(inputs.children[i].objectName === "styledInput") {
                inputs.children[i].clear();
            }
        }
    }

    function success() {
        successPopup.open();
        clearInputs();
    }

    function fail() {
        failPopup.open();
    }


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
    }

    ScrollView {
        id: scrollView
        rightPadding: 10
        anchors.top: parent.top
        anchors.topMargin: 154
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 73
        anchors.left: parent.left
        anchors.leftMargin: 60
        anchors.right: parent.right
        anchors.rightMargin: 73
        ScrollBar.horizontal.policy: ScrollBar.AlwaysOff

        Column {
            id: inputs
            width: scrollView.width
            spacing: 15

            StyledInput {
                id: firstNameInput
                height: 80
                anchors.left: parent.left
                anchors.leftMargin: 0
                anchors.right: parent.right
                anchors.rightMargin: 0
                placeholder: "first name"
                titleText: "First Name"

            }

            StyledInput {
                id: lastNameInput
                height: 80
                anchors.left: parent.left
                anchors.leftMargin: 0
                anchors.right: parent.right
                anchors.rightMargin: 0
                placeholder: "last name"
                titleText: "Last Name"
            }

            StyledInput {
                id: mailInput
                height: 80
                anchors.left: parent.left
                anchors.leftMargin: 0
                anchors.right: parent.right
                anchors.rightMargin: 0
                inputMethodHints: Qt.ImhEmailCharactersOnly
                inputMask: ""
                placeholder: "email@email.com"
                titleText: "E-mail"
            }

            StyledInput {
                id: loginInput
                height: 80
                anchors.left: parent.left
                anchors.leftMargin: 0
                anchors.right: parent.right
                anchors.rightMargin: 0
                placeholder: "login"
                titleText: "Login"
            }

            StyledInput {
                id: passwordInput
                height: 80
                anchors.left: parent.left
                anchors.leftMargin: 0
                anchors.right: parent.right
                anchors.rightMargin: 0
                placeholder: "password"
                titleText: "Password"
            }
        }
    }

    InfoPopup {
        id: successPopup
        anchors.centerIn: parent
        message: "User added successfully to an app"
    }

    InfoPopup {
        id: failPopup
        anchors.centerIn: parent
        message: "Incorect data passed, can't add user to an app"
    }

    Rectangle {
        id: scrollViewMaskBottom
        x: 0
        y: 624
        color: background.color
        anchors.top: scrollView.bottom
        anchors.topMargin: 0
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.right: parent.right
        anchors.rightMargin: 0
    }

    Rectangle {
        id: scrollViewMaskTop
        x: 4
        y: -4
        color: background.color
        anchors.top: parent.top
        anchors.rightMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        anchors.bottom: scrollView.top
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottomMargin: 0
    }

    PushButton {
        id: addButton
        objectName: "addButton"
        x: 491
        y: 644
        width: 136
        height: 40
        anchors.right: parent.right
        anchors.rightMargin: 73
        font.family: "Rubik"
        display: AbstractButton.TextOnly
        text: qsTr("Add User")
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 17
        anchors.leftMargin: 496
        onClicked: {
            userAddition(loginInput.inputText, passwordInput.inputText, mailInput.inputText);
        }
    }

    Text {
        id: desc
        x: 70
        y: 750
        width: 309
        height: 25
        color: "#4c26282a"
        text: qsTr("Add a user to an app")
        anchors.top: parent.top
        anchors.topMargin: 123
        anchors.left: parent.left
        anchors.leftMargin: 70
        font.pixelSize: 18
        font.family: "Rubik"
    }

    Text {
        id: title
        x: 70
        y: 677
        width: 328
        height: 75
        color: "#26282a"
        text: qsTr("Users")
        anchors.top: parent.top
        anchors.topMargin: 50
        anchors.left: parent.left
        anchors.leftMargin: 70
        font.weight: Font.Bold
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignLeft
        font.pixelSize: 60
        font.family: "Rubik"
    }
}


