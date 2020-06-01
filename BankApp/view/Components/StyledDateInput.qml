import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

Item {
    property alias titleText: input.titleText
    property alias readOnly: input.readOnly
    width: 640
    height: 80

    StyledInput{
        id: input
        width: parent.width
        height: parent.height
        placeholder: "0.00"
        inputMask: "Every 9 day of the month"
    }
}
