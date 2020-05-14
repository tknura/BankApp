import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3
import QtGraphicalEffects 1.14

Item {
    width: 250
    height: 150

    property bool isDisabled: false
    property string accAmountText: qsTr("9999,99")
    property string accCurrencyText: qsTr("PLN")
    property string accNumberText: qsTr("0000 1111 2222 3333")
    property string accTypeText: qsTr("Account Type")
    property color shadowNormal: "#a2a2a2"
    property color shadowChecked: "#259fc4"
    property var buttongroup: null;

    function enable() {
        button.state = "base";
    }

    function disable() {
        button.state = "disabled";
    }

    function setButtonGroup (bg) {
        button.setButtonGroup(bg);
    }

    Component.onCompleted: {
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

        function setButtonGroup (bg) {
            ButtonGroup.group = bg;
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

        Row {
            id: row
            height: 47
            anchors.right: parent.right
            anchors.rightMargin: 50
            anchors.left: parent.left
            anchors.leftMargin: 51
            anchors.top: parent.top
            anchors.topMargin: 67
            layoutDirection: Qt.LeftToRight
            spacing: 5

            Text {
                id: accAmount
                width: 78
                height: 44
                color: "#259fc4"
                text: accAmountText
                font.weight: Font.Normal
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignLeft
                font.pixelSize: 22
                font.family: "Rubik"
            }

            Text {
                id: accCurrency
                width: 54
                height: 45
                text: accCurrencyText
                color: accAmount.color
                font.weight: Font.Bold
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignLeft
                font.pixelSize: accAmount.font.pixelSize
                font.family: "Rubik"
            }




        }

        Text {
            id: accNumber
            x: -14
            y: 31
            height: 16
            color: "#9b9b9b"
            text: accNumberText
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
            text: accTypeText
            font.weight: Font.Medium
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
                x: -12
                y: -12
                color: "#ffffff"
                anchors.fill: parent
                radius: background.radius
            }

            Text {
                id: disabledText
                x: -12
                y: -12
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








/*##^##
Designer {
    D{i:9;anchors_width:133;anchors_x:51;anchors_y:67}
}
##^##*/
