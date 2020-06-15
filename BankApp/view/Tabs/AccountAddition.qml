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

    property var usersModel

    signal addPersonalAcc(string number, string user, string balance);
    signal addSavingsAcc(string number, string user, string balance, string interest);
    signal addChildAcc(string number, string user, string balance, string dailyLimit, string parent);
    signal addCurrencyAcc(string number, string user, string balance);//todo
    signal addFamilyAcc(string number, string user, string balance);//todo
    signal addFirmAcc(string number, string user, string balance);//todo

    signal newAccNumber();


    function addAccount(type) {
        if(accNumberInput.inputText.length !== 0 && balanceInput.inputText.length !== 0){
            switch(type){
            case "personal":
                addPersonalAcc(accNumberInput.inputText, ownerCombo.currentOption,
                               balanceInput.inputText);
                break;
            case "savings":
                if(dynamicInputs.children[0].inputText.length !== 0){
                    addSavingsAcc(accNumberInput.inputText, ownerCombo.currentOption,
                                  balanceInput.inputText, dynamicInputs.children[0].inputText);
                }
                break;
            case "child":
                if(dynamicInputs.children[0].inputText.length !== 0){
                    addChildAcc(accNumberInput.inputText, ownerCombo.currentOption,
                                  balanceInput.inputText, dynamicInputs.children[0].inputText,
                                  dynamicInputs.children[1].currentOption);
                }
                break;
            case "currency":

                break;
            case "family":

                break;
            case "firm":

                break;
            }
        }
    }

    function clearInputs() {
        for(var i = 0; i < inputs.children.length; ++i) {
            if(inputs.children[i].objectName === "styledInput"
                    || inputs.children[i].objectName === "styledCombo") {
                inputs.children[i].clear();
            }
        }
        newAccNumber();
    }

    function success() {
        popup.message = "Account added successfully to user";
        popup.open();
        clearInputs();
    }

    function fail() {
        popup.message = "Incorect data passed, can't add account to user";
        popup.open();
    }

    Component.onCompleted: {
        addInputs(accTypeCombo.currentOption);
    }

    function addInputs(type){
        switch(type){
        case "personal":
            addPersonalInputs();
            break;
        case "savings":
            addSavingsInputs();
            break;
        case "child":
            addChildInputs();
            break;
        case "currency":
            addCurrencyInputs();
            break;
        case "family":
            addFamilyInputs();
            break;
        case "firm":
            addFirmInputs();
            break;
        }
    }

    function addPersonalInputs() {
    }

    function addSavingsInputs() {
        dynamicInputs.addTextInput("Interest", "000.000%", "999.999%;0");
    }

    function addChildInputs() {
        dynamicInputs.addCurrencyInput("Daily limit");
        dynamicInputs.addCombo("Parent", usersModel);
    }

    function addCurrencyInputs() {
    }

    function addFamilyInputs() {
    }

    function addFirmInputs() {
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
        anchors.left: parent.left
        anchors.leftMargin: 60
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 76
        anchors.right: parent.right
        anchors.rightMargin: 66
        ScrollBar.horizontal.policy: ScrollBar.AlwaysOff

        Column {
            id: inputs
            width: scrollView.width
            spacing: 15

            StyledCombo {
                id: accTypeCombo
                titleText: "Type"
                objectName: "accTypeCombo"
                height: 80
                width: parent.width
                onOptionChanged: {
                    dynamicInputs.remove();
                    addInputs(optName);
                }
            }

            GroupBox {
                id: accNumberGroup
                height: 80
                width: inputs.width
                padding: 0

                StyledInput {
                    id: accNumberInput
                    objectName: "accNumberInput"
                    height: accNumberGroup.height
                    anchors.left: parent.left
                    anchors.leftMargin: 0
                    anchors.right: rerollButton.left
                    anchors.rightMargin: 5
                    titleText: "Number"
                    readOnly: true
                }

                PushButton {
                    id: rerollButton
                    objectName: "rerollButton"
                    x: 537
                    y: 39
                    width: 40
                    height: width
                    text: "Reroll"
                    anchors.bottom: parent.bottom
                    anchors.bottomMargin: 5
                    anchors.right: parent.right
                    anchors.rightMargin: 5
                    onClicked: newAccNumber();
                }

                background: Rectangle {
                    color: "transparent"
                    border.color: "transparent"
                }
            }

            StyledCombo {
                id: ownerCombo
                titleText: "User"
                objectName:  "ownerCombo"
                model: usersModel
                height: 80
                width: parent.width
            }

            StyledCurrencyInput {
                id: balanceInput
                height: 80
                width: parent.width
                titleText: "Balance"
            }

            DynamicInputs {
                id: dynamicInputs
                width: parent.width
                spacing: parent.spacing
            }
        }
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

    InfoPopup {
        id: popup
        anchors.centerIn: parent
        message: "Account added successfully to user"
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

    PushButton {
        id: addButton
        objectName: "addButton"
        x: 491
        y: 642
        width: 136
        height: 40
        anchors.right: parent.right
        anchors.rightMargin: 73
        font.family: "Rubik"
        display: AbstractButton.TextOnly
        text: "Add Account"
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 18
        anchors.leftMargin: 500
        onClicked: {
            addAccount(accTypeCombo.currentOption);
        }
    }
}
