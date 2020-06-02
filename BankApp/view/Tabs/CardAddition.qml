import QtQuick 2.0
import QtQuick.Controls 2.3
import QtGraphicalEffects 1.14
import components 1.0

Item {
    id: element
    objectName: "cardAddition"
    visible: true
    width: 700
    height: 700

    property var cardsModel
    property var accountsModel

    signal newCcvNumber();
    signal newCardNumber();

    signal addPrePaid(string number, string ccv, string accNum, string transLim);
    signal addCredit(string number, string ccv, string accNum, string transLim,
                     string maxCredit, string billingDate);
    signal addDebit(string number, string ccv, string accNum, string transLim, string maxDebt);

    function addCard(type) {
        if(limitInput.inputText.length !== 0){
            switch(type){
            case "pre-paid":
                addPrePaid(cardNumberInput.inputText, ccvNumberInput.inputText, ownerAcc.currentOption,
                           limitInput.inputText);
                break;
            case "debit":
                if(dynamicInputs.children[0].inputText.length !== 0){
                    addDebit(cardNumberInput.inputText, ccvNumberInput.inputText, ownerAcc.currentOption,
                             limitInput.inputText, inputs.children[0].inputText);
                }
                break;
            case "credit":
                if( dynamicInputs.children[0].inputText !== 0 && dynamicInputs.children[1].inputText !== 0){
                    addCredit(cardNumberInput.inputText, ccvNumberInput.inputText, ownerAcc.currentOption,
                              limitInput.inputText, dynamicInputs.children[0].inputText, dynamicInputs.children[1].inputText);
                }
                break;
            }
        }
    }

    function clearInputs() {
        for(var i = 0; i < inputs.children.length; ++i) {
            if(inputs.children[i].objectName === "styledInput") {
                inputs.children[i].clear();
            }
        }
        newCcvNumber();
        newCardNumber();
    }

    function success() {
        popup.message = "Card added successfully to an account";
        popup.open();
        clearInputs();
    }

    function fail() {
        popup.message = "Incorect data passed, can't add card to account";
        popup.open();
    }

    function addInputs(type){
        switch(type){
        case "pre-paid":
            addPrePaidInputs();
            break;
        case "debit":
            addDebitInputs();
            break;
        case "credit":
            addCreditInputs();
            break;
        }
    }

    function addPrePaidInputs() {
    }

    function addDebitInputs() {
        dynamicInputs.addCurrencyInput("Max debt");
    }

    function addCreditInputs() {
        dynamicInputs.addCurrencyInput("Max credit");
        dynamicInputs.addTextInput("Billing date")
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
                id: cardTypeCombo
                titleText: "Type"
                objectName: "cardTypeCombo"
                height: 80
                width: parent.width
                onOptionChanged: {
                    dynamicInputs.remove();
                    addInputs(optName);
                }
            }

            GroupBox {
                id: cardNumberGroup
                height: 80
                width: inputs.width
                padding: 0

                StyledInput {
                    id: cardNumberInput
                    objectName: "cardNumberInput"
                    height: cardNumberGroup.height
                    anchors.left: parent.left
                    anchors.leftMargin: 0
                    anchors.right: cardRerollButton.left
                    anchors.rightMargin: 5
                    titleText: "Number"
                    readOnly: true
                }

                PushButton {
                    id: cardRerollButton
                    objectName: "cardRerollButton"
                    x: 537
                    y: 39
                    width: 40
                    height: width
                    text: "Reroll"
                    anchors.bottom: parent.bottom
                    anchors.bottomMargin: 5
                    anchors.right: parent.right
                    anchors.rightMargin: 5
                    onClicked: newCardNumber();
                }

                background: Rectangle {
                    color: "transparent"
                    border.color: "transparent"
                }
            }

            GroupBox {
                id: ccvNumberGroup
                height: 80
                width: inputs.width
                padding: 0

                StyledInput {
                    id: ccvNumberInput
                    objectName: "ccvNumberInput"
                    height: ccvNumberGroup.height
                    anchors.left: parent.left
                    anchors.leftMargin: 0
                    anchors.right: ccvRerollButton.left
                    anchors.rightMargin: 5
                    titleText: "CCV"
                    readOnly: true
                }

                PushButton {
                    id: ccvRerollButton
                    objectName: "ccvRerollButton"
                    x: 537
                    y: 39
                    width: 40
                    height: width
                    text: "Reroll"
                    anchors.bottom: parent.bottom
                    anchors.bottomMargin: 5
                    anchors.right: parent.right
                    anchors.rightMargin: 5
                    onClicked: newCcvNumber();
                }

                background: Rectangle {
                    color: "transparent"
                    border.color: "transparent"
                }
            }

            StyledCombo {
                id: ownerAcc
                titleText: "Account"
                objectName:  "ownerAcc"
                model: accountsModel
                height: 80
                width: parent.width
            }

            StyledCurrencyInput {
                id: limitInput
                width: parent.width
                height: 80
                titleText: "Transaction limit"
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
        message: "Card added successfully to an account"
    }

    Text {
        id: title
        width: 328
        height: 75
        color: "#26282a"
        text: qsTr("Cards")
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
        text: qsTr("Add a card to specific account")
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
        text: qsTr("Add Card")
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 18
        anchors.leftMargin: 500
        onClicked: {
            addCard(cardTypeCombo.currentOption);
        }
    }
}
