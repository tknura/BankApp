import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3
import QtGraphicalEffects 1.14

Item {
    width: 250
    height: 150

    property alias checked: button.checked
    property bool isDisabled: false
    property alias accAmountText: accAmount.text
    property alias accCurrencyText: accCurrency.text
    property alias accNumberText: accNumber.text
    property alias accTypeText: accType.text
    property color shadowNormal: "#a2a2a2"
    property color shadowChecked: "#259fc4"
    property var buttongroup: null
    property var itemToRefresh

    function enable() {
        button.state = "base";
    }

    function disable() {
        button.state = "disabled";
    }

    onIsDisabledChanged: {
        if(isDisabled){
            disable();
        }
        else {
            enable();
        }
    }

    RadioButton {
        id: button
        enabled: true
        autoExclusive: true
        anchors.top: parent.top
        anchors.topMargin: 8
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 8
        anchors.left: parent.left
        anchors.leftMargin: 8
        anchors.right: parent.right
        anchors.rightMargin: 8
        ButtonGroup.group:  buttongroup
        background: Rectangle {
            id: background
            color: "#ffffff"
            border.color: button.checked ? "#259fc4" : "transparent"
            radius: 20
            anchors.fill: parent
        }
        indicator: null
        onCheckedChanged: {
            if(checked) {
                itemToRefresh.updateNum(accNumberText);
            }
        }

        states: [
            State {
                name: "disabled"
                PropertyChanges {
                    target: button
                    enabled: false
                }
                PropertyChanges {
                    target: accAmount
                    color: "#7b7b7b"
                }

                PropertyChanges {
                    target: disabledGroup
                    visible: true
                }
            }
        ]


            Text {
                id: accAmount
                height: 44
                anchors.top: parent.top
                anchors.topMargin: 67
                //anchors.bottom: parent.bottom
                anchors.horizontalCenter: parent.horizontalCenter

                color: "#259fc4"
                text: qsTr("9999,99")
                anchors.horizontalCenterOffset: -23
                font.weight: Font.Normal
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignLeft
                font.pixelSize: 22
                font.family: "Rubik"
            }

            Text {
                id: accCurrency
                height: 44
                anchors.top: accAmount.top
                anchors.bottom: accAmount.bottom
                anchors.left: accAmount.right
                text: qsTr("PLN")
                anchors.bottomMargin: 0
                anchors.leftMargin: 1
                anchors.topMargin: 0
                color: accAmount.color
                font.weight: Font.Bold
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignLeft
                font.pixelSize: accAmount.font.pixelSize
                font.family: "Rubik"
            }
       //}

        Text {
            id: accNumber
            x: -14
            y: 31
            height: 16
            color: "#9b9b9b"
            text: qsTr("0000111122223333")
            horizontalAlignment: Text.AlignHCenter
            anchors.top: parent.top
            anchors.topMargin: 45
            anchors.left: parent.left
            anchors.leftMargin: 0
            anchors.right: parent.right
            anchors.rightMargin: 0
            font.family: "Rubik"
        }

        Text {
            id: accType
            x: -14
            y: 5
            height: 26
            color: "#393e46"
            text: qsTr("Account Type")
            font.weight: Font.Medium
            font.capitalization: Font.Capitalize
            verticalAlignment: Text.AlignVCenter
            anchors.top: parent.top
            anchors.topMargin: 19
            anchors.left: parent.left
            anchors.leftMargin: 0
            anchors.right: parent.right
            anchors.rightMargin: 0
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 18
            font.family: "Rubik"
        }

        GroupBox {
            id: disabledGroup
            padding: 0
            rightPadding: 0
            bottomPadding: 0
            leftPadding: 0
            topPadding: 0
            visible: false
            anchors.fill: parent
            background: Rectangle {
                color: "transparent"
                border.color: "transparent"
            }

            Rectangle {
                id: disabledShadow
                color: "#ffffff"
                anchors.fill: parent
                radius: background.radius
                opacity: 0.9
            }

            Text {
                id: disabledText
                font.family: "Rubik"
                text: qsTr("Transactions\n disabled")
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
                font.capitalization: Font.AllUppercase
                font.weight: Font.Bold
                font.pixelSize: 18
                anchors.fill: parent
            }

        }
    }

    DropShadow {
        x: 8
        y: 8
        color: button.checked ? shadowChecked : shadowNormal
        anchors.fill: button
        horizontalOffset: 0
        verticalOffset: 0
        radius: 20
        samples: 25
        spread: 0
        source: button
    }



}









