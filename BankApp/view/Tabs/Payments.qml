import QtQuick 2.0
import QtQml 2.2
import components 1.0
import QtQuick.Controls 2.13

Item {
    id: payments
    objectName: "payments"
    visible: true
    width: 700
    height: 700


    property date currentDate: new Date()
    property alias accountsList : accountsList
    property var userAccNumbersModel
    property var paymentTypes: ["external", "internal"]

    signal makePayment(string outAccNum, string amount, string title, string date,
                       string name, string inAccNum, string adresss)

    Component.onCompleted: {
        addInputs(paymentTypes[0]);
    }

    function addInputs(type){
        switch(type){
        case "internal":
            addInternalInputs();
            break;
        case "external":
            addExternalInputs();
            break;
        }
    }

    function addInternalInputs() {
        dynamicInputs.addCombo("Transfer to", userAccNumbersModel);
    }

    function addExternalInputs() {
        //friendslist
        dynamicInputs.addTextInput("First & Last Name", "John Smith");
        dynamicInputs.addTextInput("Adress", "Road 21/37, 22-330 City");
        dynamicInputs.addTextInput("Account number", "", "9999999999999999;0");
    }

    function clearInputs() {
        for(var i = 0; i < inputs.children.length; ++i) {
            if(inputs.children[i].objectName === "styledInput"
                    || inputs.children[i].objectName === "styledCombo") {
                inputs.children[i].clear();
            }
        }
    }

    function success() {
        popup.message = "Successfully made a payment";
        popup.open();
        clearInputs();
    }

    function fail() {
        popup.message = "Incorect data passed, can't make a payment";
        popup.open();
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

    InfoPopup {
        id: popup
        anchors.centerIn: parent
        message: "Card added successfully to an account"
    }

    ScrollView {
        id: scrollView
        rightPadding: 10
        anchors.top: accountsList.bottom
        anchors.topMargin: 6
        anchors.left: parent.left
        anchors.leftMargin: 63
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 70
        anchors.right: parent.right
        anchors.rightMargin: 63
        ScrollBar.horizontal.policy: ScrollBar.AlwaysOff

        Column {
            id: inputs
            width: scrollView.width
            spacing: 15

            StyledCombo {
                id: paymentTypeCombo
                titleText: "Type"
                objectName: "paymentTypeCombo"
                height: 80
                width: parent.width
                onOptionChanged: {
                    dynamicInputs.remove();
                    addInputs(optName);
                }
                model: paymentTypes
            }

            StyledInput {
                id: titleInput
                titleText: "Title"
                placeholder: "Payment title"
                height: 80
                objectName: "titleInput"
                width: parent.width
            }

            DynamicInputs {
                id: dynamicInputs
                width: parent.width
                spacing: parent.spacing
            }

            StyledCurrencyInput {
                id: amount
                titleText: "Amount"
                objectName: "amountInput"
                height: 80
                width: parent.width
            }
        }
    }


    Rectangle {
        id: scrollViewMaskTop
        x: 0
        y: 0
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
        y: 700
        height: 0
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

    AccountButtonList {
        id: accountsList
        y: 148
        height: 166
        anchors.right: parent.right
        anchors.rightMargin: 63
        anchors.left: parent.left
        anchors.leftMargin: 63
        onCheckedAccNumberChanged: {
            console.log(checkedAccNumber);
        }
    }



    Text {
        id: desc
        x: 70
        y: 123
        width: 309
        height: 25
        color: "#4c26282a"
        text: qsTr("Make a new payment")
        font.pixelSize: 18
        font.family: "Rubik"
    }

    Text {
        id: title
        x: 70
        y: 50
        width: 328
        height: 75
        color: "#26282a"
        text: qsTr("Payments")
        font.weight: Font.Bold
        verticalAlignment: Text.AlignVCenter
        horizontalAlignment: Text.AlignLeft
        font.pixelSize: 60
        font.family: "Rubik"
    }



    PushButton {
        id: makePaymentButton
        objectName: "makePaymentButton"
        x: 491
        y: 642
        width: 136
        height: 40
        anchors.right: parent.right
        anchors.rightMargin: 73
        font.family: "Rubik"
        display: AbstractButton.TextOnly
        text: qsTr("Make payment")
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 18
        anchors.leftMargin: 500
        onClicked: {
            if(paymentTypeCombo.currentOption == "internal"){
                makePayment(accountsList.checkedAccNumber, amount.inputText, titleInput.inputText,
                            currentDate.toLocaleDateString(Qt.locale(),"yyyy-MM-dd"), "", dynamicInputs.children[0].inputText, "");
            }
            else {
                makePayment(accountsList.checkedAccNumber, amount.inputText, titleInput.inputText,
                            currentDate.toLocaleDateString(Qt.locale(),"yyyy-MM-dd"), dynamicInputs.children[0].inputText,
                            dynamicInputs.children[2].inputText, dynamicInputs.children[1].inputText);
                //i + 1 when friends will be added
            }

        }
    }
}



/*##^##
Designer {
    D{i:9;anchors_width:221;anchors_x:9}D{i:12;anchors_width:221;anchors_x:9}
}
##^##*/
