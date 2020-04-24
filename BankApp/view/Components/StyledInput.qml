import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

Item {
    id: styledInput
    visible: true
    width: 640
    height: 80
    property alias inputText: textField.text

    FontLoader { id: rubikBold; source: "/resources/fonts/Rubik-Bold.ttf" }
    FontLoader { id: rubikMedium; source: "/resources/fonts/Rubik-Medium.ttf" }

    function setHashed(bool) {
        if(bool){
            textField.echoMode = TextInput.Password
        }
        else {
            textField.echoMode = TextInput.Normal
        }
    }

    function setTitle(text) {
        title.text = qsTr(text);
    }

    function setPlaceholderText(text) {
        textField.placeholderText = qsTr(text);
    }

    function getText() {
        return textField.text;
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
        text: qsTr("Title")
        anchors.top: parent.top
        anchors.topMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
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
        placeholderText: "placeholder"
        font.family: "Rubik"
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
            color: "#F7F7F7"
            border.color: "#F7F7F7"
            border.width: 2
            radius: 25
        }
    }
}






