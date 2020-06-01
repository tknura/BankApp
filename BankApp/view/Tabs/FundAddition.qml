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
        case "savings":
            addSavingsInputs();
            break;
        case "retirement":
            addRetirementInputs();
            break;
        case "investment":
            addInvestmentInputs();
            break;
        }
    }

    function addSavingsInputs() {
        removeDynamicInputs();
    }

    function addRetirementInputs() {
        removeDynamicInputs();
        addCurrencyInput("Monthly in");
        addCurrencyInput("Monthly out");
       //addCheckbox("user retired");
    }

    function addInvestmentInputs() {
        removeDynamicInputs();
    }

    function addTextInput(title = "", placeholder = "", inputMask) {
        var component;
        var sprite;
        component = Qt.createComponent("qrc:/components/StyledInput.qml");
        sprite = component.createObject(dynamicInputs,
                                        {
                                           width: dynamicInputs.width,
                                           titleText: title,
                                           placeholder: placeholder,
                                           inputMask: inputMask
                                        });
    }

    function addCombo(title, objectName) {
        var component;
        var sprite;
        component = Qt.createComponent("qrc:/components/StyledCombo.qml");
        sprite = component.createObject(dynamicInputs,
                                        {
                                           width: dynamicInputs.width,
                                           titleText: title,
                                           objectName: objectName,
                                           model: usersModel
                                        });
    }

    function addCurrencyInput(title) {
        var component;
        var sprite;
        component = Qt.createComponent("qrc:/components/StyledCurrencyInput.qml");
        sprite = component.createObject(dynamicInputs,
                                        {
                                           width: dynamicInputs.width,
                                           titleText: title
                                        });
    }

    function addCheckbox(text) {
        var component;
        var sprite;
        component = Qt.createComponent("qrc:/components/StyledCheckBox.qml");
        sprite = component.createObject(dynamicInputs,
                                        {
                                           width: dynamicInputs.width,
                                           text: text
                                        });
    }

    function removeDynamicInputs() {
        for(var i = 0; i < dynamicInputs.children.length; ++i) {
            dynamicInputs.children[i].destroy(0);
        }
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

//            StyledCheckBox {
//                text: "is retired"
//            }

            Column {
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
        text: qsTr("Add User")
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 18
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
