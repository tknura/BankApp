import QtQuick 2.0
import QtQuick.Controls 2.3
import "qrc:/view/Components/"

Item {
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


    InfoPopup {
        id: successPopup
        width: 420
        height: 180
        anchors.centerIn: parent
        padding: 20
        modal: true
        focus: true
        title: "User added"
        description: "User added successfully to an app"
        closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutside
    }

    InfoPopup {
        id: failPopup
        width: 420
        height: 180
        anchors.centerIn: parent
        padding: 20
        modal: true
        focus: true
        title: "User addition failed"
        description: "Incorect data passed, check information boxes for more info"
        closePolicy: Popup.CloseOnEscape | Popup.CloseOnPressOutside
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

    Text {
        id: title
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

    Text {
        id: desc
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


    Column {
        id: inputs
        height: 462
        anchors.left: parent.left
        anchors.leftMargin: 61
        anchors.top: parent.top
        anchors.topMargin: 163
        anchors.right: parent.right
        anchors.rightMargin: 73
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

    PushButton {
        id: addButton
        objectName: "addButton"
        x: 491
        y: 642
        width: 136
        height: 40
        anchors.right: parent.right
        anchors.rightMargin: 73
        anchors.top: parent.top
        anchors.topMargin: 643
        font.family: "Rubik"
        display: AbstractButton.TextOnly
        text: qsTr("Add User")
        anchors.bottomMargin: 16
        anchors.leftMargin: 496
        contentItem: Text {
            text: addButton.text
            font: addButton.font
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            color: "#259FC4"
        }
        background: Rectangle {
            color: addButton.pressed ? "#75b4c5" : addButton.hovered ? "#7cd2ed" : "#A3E7FC"
            radius: 25
        }
        onClicked: {
            userAddition(loginInput.inputText, passwordInput.inputText, mailInput.inputText);
        }
    }









}



