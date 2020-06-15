import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

Item {
    id: styledCombo
    objectName: "styledCombo"
    visible: true
    width: 640
    height: 80
    property string titleText: "Title"
    property alias model: comboBox.model
    property string currentOption: comboBox.displayText

    function clear() {
        comboBox.currentIndex = 0;
    }

    signal optionChanged(string optName)

    onModelChanged:  {
        currentOption = comboBox.displayText;
        optionChanged(comboBox.displayText);
    }

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

    ComboBox {
        id: comboBox
        wheelEnabled: true
        objectName: "comboBox"
        leftPadding: 25
        anchors.bottomMargin: 0
        anchors.topMargin: 30
        anchors.bottom: parent.bottom
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.leftMargin: 0
        anchors.right: parent.right
        font.family: "Rubik"

        onActivated:  {
            currentOption = displayText;
            optionChanged(displayText);
        }

        contentItem: Text {
            leftPadding: 0
            text: comboBox.displayText
            verticalAlignment: Text.AlignVCenter
            color: "#259fc4"
            font.weight: Font.Medium
        }

        background: Rectangle {
            id: background
            color: comboBox.hovered ? "#FFFFFF" : "#F7F7F7"
            border.color: "transparent"
            radius: 25
        }

        delegate: ItemDelegate {
                  id: itemDlgt
                  width: parent.width

                  contentItem: Text {
                    id:textItem
                    text: modelData
                    color: hovered ? "white" : "#259fc4"
                    font.weight: hovered ? Font.Medium : Font.Normal
                    elide: Text.ElideRight
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignLeft
                  }

                  background: Rectangle {
                    radius: 20
                    color: itemDlgt.hovered ? "#a3e7fc" : "#F7F7F7";
                    anchors.left: itemDlgt.left
                    anchors.leftMargin: 0
                    width: itemDlgt.width
                  }
        }
        popup: Popup {
            y: comboBox.height
            width: comboBox.width

            background: Rectangle {
                color: "#F7F7F7"
                border.color: background.border.color
                radius: background.radius
             }

            contentItem: ListView {
                implicitHeight: contentHeight
                model: comboBox.delegateModel
                currentIndex: comboBox.highlightedIndex
                highlightMoveDuration: 0

                Rectangle {
                    width: parent.width
                    height: parent.height
                    color: "transparent"
                    border.color: "transparent"
                }

                ScrollIndicator.vertical: ScrollIndicator { }
            }
        }
    }
}
