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
        firstNameInput.clear();
        lastNameInput.clear();
        mailInput.clear();
        loginInput.clear();
        passwordInput.clear();
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
        text: qsTr("Accounts")
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
        text: qsTr("Add an account to specific user")
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

        ComboBox {
            id: comboBox
            anchors.left: parent.left
            anchors.leftMargin: 0
            anchors.right: parent.right
            anchors.rightMargin: 0
        }
    }

    Button {
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
        contentItem: Text {
            font: addButton.font
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            color: "#259FC4"
            text: "Add Account"
        }
        background: Rectangle {
            color: addButton.pressed ? "#75b4c5" : addButton.hovered ? "#7cd2ed" : "#A3E7FC"
            radius: 25
        }
        onClicked: {
            userAddition(loginInput.inputText, passwordInput.inputText, mailInput.inputText);
            clearInputs();
        }
    }
}



