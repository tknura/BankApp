import QtQuick 2.0
import QtQuick.Controls 2.3
import QtGraphicalEffects 1.14
import components 1.0

Item {
    id: element
    objectName: "accountAddition"
    visible: true
    width: 700
    height: 700

    property alias model: accTypeCombo.model

    function clearInputs() {
        for(var i = 0; i < inputs.children.length; ++i) {
            if(inputs.children[i].objectName === "styledInput") {
                inputs.children[i].clear();
            }
        }
    }

    function addInputs(type){
        switch(type){
        case "Personal":
            console.log("personal!")
            break;
        case "Savings":
            console.log("savings!")
            break;
        case "Child":
            console.log("child!")
            break;
        case "Currency":
            console.log("currency!")
            break;
        case "Family":
            console.log("firm!")
            break;
        case "Firm":
            console.log("firm!")
            break;
        }
    }

    function addPersonalInputs(){
        var component;
        var sprite;
        component = Qt.createComponent("AccountButton.qml");
        sprite = component.createObject
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


    Item {
        id: element1
        anchors.fill: scrollView

        Column {
            id: staticInputs
            x: 0
            y: 0
            height: 650
            anchors.left: parent.left
            anchors.leftMargin: 0
            anchors.right: parent.right
            anchors.rightMargin: 0
            spacing: 15


            StyledCombo {
                id: accTypeCombo
                titleText: "Type"
                objectName:  "accTypeCombo"
                model: ["Personal", "Savings", "Child", "Currency", "Family", "Firm"]
                height: 80
                width: staticInputs.width
                onOptionChanged: {
                    addInputs(optName);
                }
            }

            GroupBox {
                id: accNumberGroup
                height: 80
                width: staticInputs.width
                padding: 0

                StyledInput {
                    id: firstNameInput
                    height: accNumberGroup.height
                    inputMask: "9999 9999 9999 9999"
                    anchors.left: parent.left
                    anchors.leftMargin: 0
                    anchors.right: refreshButton.left
                    anchors.rightMargin: 5
                    placeholder: "generated account number"
                    titleText: "Number"
                }

                PushButton {
                    id: refreshButton
                    x: 537
                    y: 39
                    width: 40
                    height: width
                    text: "Reroll"
                    anchors.bottom: parent.bottom
                    anchors.bottomMargin: 5
                    anchors.right: parent.right
                    anchors.rightMargin: 5
                }

                background: Rectangle {
                    color: "transparent"
                    border.color: "transparent"
                }
            }

            StyledCombo {
                id: ownerCombo
                titleText: "User"
                objectName:  "accTypeCombo"
                height: 80
                width: staticInputs.width
            }

            StyledInput {
                id: balanceInput
                height: 80
                width: staticInputs.width
                placeholder: "starting account balance"
                titleText: "Balance"
            }

            StyledInput {
                height: 80
                width: staticInputs.width
                placeholder: "starting account balance"
                titleText: "Balance"
            }

            StyledInput {
                height: 80
                width: staticInputs.width
                placeholder: "starting account balance"
                titleText: "Balance"
            }

            Column {
                id: dynamicInputs
                height: 80
                width: staticInputs.width
            }



        }
    }

    ScrollView {
        id: scrollView
        rightPadding: 10
        anchors.top: parent.top
        anchors.topMargin: 154
        anchors.left: parent.left
        anchors.leftMargin: 60
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 76
        anchors.right: parent.right
        anchors.rightMargin: 66
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
        anchors.bottomMargin: 19
        anchors.leftMargin: 500
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
            clearInputs();
        }
    }



}








/*##^##
Designer {
    D{i:1;invisible:true}
}
##^##*/
