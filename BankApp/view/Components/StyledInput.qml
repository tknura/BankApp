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
    property string placeholder: "placeholder"
    property bool isHashed: false
    property alias validator: textField.validator
    property alias inputMask: textField.inputMask
    property alias inputMethodHints: textField.inputMethodHints
    property alias readOnly: textField.readOnly

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

    Component.onCompleted: {
        if(isHashed) {
            setHashed(true);
        }
        else {
            setHashed(false);
        }
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
        leftPadding: 25
        anchors.bottomMargin: 0
        anchors.topMargin: 30
        anchors.bottom: parent.bottom
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.top: parent.top
        horizontalAlignment: Text.AlignLeft
        anchors.leftMargin: 0
        anchors.right: parent.right
        placeholderText: placeholder
        font.family: "Rubik"
        color: "#259fc4"
        placeholderTextColor: "#d2def5"
        selectionColor: "#a3e7fc"
        selectByMouse: true
        font.weight: Font.Medium
        readOnly: false
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
    }
}






