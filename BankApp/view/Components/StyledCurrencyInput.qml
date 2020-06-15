import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

Item {
    property alias titleText: input.titleText
    property alias readOnly: input.readOnly
    property alias inputText: input.inputText
    property alias objectName: input.objectName
    width: 640
    height: 80

    function clear() {
        input.clear();
    }

    StyledInput{
        id: input
        width: parent.width
        height: parent.height
        placeholder: "0.00"
        validator: RegExpValidator {
                regExp: /([+-]?[0-9]+(\.[0-9]{2})?)/
            }
        inputLeftPadding: 50
    }

    Text {
        id: currencyLabel
        width: 18
        anchors {
            top: input.top; bottom: input.bottom
            left: input.left; leftMargin: 25
        }
        verticalAlignment: Text.AlignVCenter
        color: input.color
        text: qsTr("PLN")
        anchors.topMargin: 29
    }
}

