import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

Item {
    id: styledInput
    objectName: "styledInput"
    visible: true
    width: 640
    height: 80

    property alias inputText: textField.text
    property string titleText: "Title"
    property alias inputMethodHints: textField.inputMethodHints
    property alias readOnly: textField.readOnly
    property alias displayText: textField.displayText
    property alias activeFocusOnPress: textField.activeFocusOnPress

    function setHashed(bool) {
        if(bool){
            textField.echoMode = TextInput.Password
        }
        else {
            textField.echoMode = TextInput.Normal
        }
    }

    function clear() {
        textField.clear();
    }

    states: [
        State {
            name: "FAILED"
            PropertyChanges {
                target: textField.background;
                state: "FAILED";
            }
        }
    ]

    Text {
        id: title
        width: 99
        height: 25
        color: "#393e46"
        text: titleText
        anchors.top: parent.top
        anchors.topMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 22
        font.weight: Font.Medium
        font.family: "Rubik"
        verticalAlignment: Text.AlignVCenter
        font.pixelSize: 20
    }

    TextField {
        id: textField
        objectName: "textInput"
        echoMode: TextInput.Normal
        leftPadding: 50
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.top: parent.top
        anchors.topMargin: 30
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        horizontalAlignment: Text.AlignLeft
        verticalAlignment: Text.AlignVCenter
        placeholderText: "0.00"
        font.family: "Rubik"
        color: "#259fc4"
        placeholderTextColor: "#d2def5"
        selectionColor: "#a3e7fc"
        selectByMouse: true
        font.weight: Font.Medium
        readOnly: false
        validator: RegExpValidator {
                regExp: /([+-]?[0-9]+(\.[0-9]{2})?)/
            }
        background: Rectangle {
            id: background
            states: [
                State {
                    name: "FAILED"
                    PropertyChanges {
                        target: background;
                        border.color: "#ED2939"
                    }
                }
            ]
            color: textField.hovered ? "#FFFFFF" : "#F7F7F7"
            border.color: "#ececec"
            border.width: 2
            radius: 25
        }

        Text {
            id: currencyLabel
            anchors {
                top: parent.top; bottom: parent.bottom
                left: parent.left; leftMargin: 25
            }
            verticalAlignment: Text.AlignVCenter
            color: parent.color
            text: qsTr("PLN")
        }
    }
}






