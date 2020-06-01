import QtQuick 2.0
import QtQuick.Controls 2.3
import QtGraphicalEffects 1.14
import components 1.0

Item {
    id: element
    objectName: "fundAddition"
    visible: true
    width: 700
    height: 700

    property var usersModel

    function clearInputs() {
        for(var i = 0; i < inputs.children.length; ++i) {
            if(inputs.children[i].objectName === "styledInput") {
                inputs.children[i].clear();
            }
        }
    }

    function addInputs(type){
        switch(type){
        case "investment":
            addInvestmentInputs();
            break;
        case "savings":
            addSavingsInputs();
            break;
        case "retirement":
            addRetirementInputs();
            break;
        }
    }

    function addSavingsInputs() {
        dynamicInputs.removeDynamicInputs();
        dynamicInputs.addDateInput("Start date");
        dynamicInputs.addDateInput("End date");
    }

    function addRetirementInputs() {
        dynamicInputs.removeDynamicInputs();
        dynamicInputs.addCurrencyInput("Monthly in");
        dynamicInputs.addCurrencyInput("Monthly out");
       //addCheckbox("user retired");
    }

    function addInvestmentInputs() {
        dynamicInputs.removeDynamicInputs();
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
                id: fundTypeCombo
                titleText: "Type"
                objectName: "fundTypeCombo"
                height: 80
                width: parent.width
                onOptionChanged: {
                    addInputs(optName);
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
                id: minAmountInput
                objectName: "minAmountInput"
                height: 80
                width: parent.width
                titleText: "Minimal amount"
            }

            StyledInput {
                id: maxRateInput
                objectName: "maxRateInput"
                height: 80
                width: parent.width
                titleText: "Maximal Rate"
                placeholder: "000.00%"
                inputMask: "999.99%;0"
            }

            StyledInput {
                id: feeInput
                objectName: "feeInput"
                height: 80
                width: parent.width
                titleText: "Fee"
                placeholder: "000.00%"
                inputMask: "999.99%;0"
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


    Text {
        id: title
        width: 328
        height: 75
        color: "#26282a"
        text: qsTr("Funds")
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
        text: qsTr("Add a fund to specific user")
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
        text: qsTr("Add Fund")
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 18
        anchors.leftMargin: 500
        onClicked: {
            clearInputs();
        }
    }
}
