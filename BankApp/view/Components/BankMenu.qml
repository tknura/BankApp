import QtQuick 2.0
import QtQuick.Controls 2.13
import QtGraphicalEffects 1.14

Item {

    // model should contain:
    // string buttonText
    // url buttonIcon
    property alias model: listView.model

    // stack view where item should be replaced in
    property var screenStack
    // content which is replaced on stack on list item click (should match order
    // in model to work properly)
    property var contentArray

    signal logOut();
    signal tabChanged(var tab);

    Rectangle {
        id: background
        color: "#ffffff"
        width: parent.width
        height: parent.height

        ListView {
            id: listView
            anchors.top: parent.top
            anchors.topMargin: 129
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 60
            highlightRangeMode: ListView.NoHighlightRange
            spacing: 0
            boundsBehavior: Flickable.StopAtBounds
            anchors.left: parent.left
            anchors.leftMargin: 0
            anchors.right: parent.right
            anchors.rightMargin: 0
            delegate:
                Item {
                id: button
                width: parent.width
                height: 60

                GroupBox {
                    width: parent.width
                    height: parent.height
                    leftPadding: 25
                    background: Rectangle {
                        color: "transparent"
                        border.color: "transparent"
                    }

                    MouseArea {
                        anchors.fill: parent
                        onClicked: {
                            listView.currentIndex = index;
                            screenStack.replace(contentArray[index]);
                            tabChanged(contentArray[index]);
                        }
                    }

                    Image {
                        id: butIcon
                        width: 20
                        height: 20
                        source: buttonIcon
                        anchors.verticalCenter: parent.verticalCenter
                        sourceSize.width: 20
                        sourceSize.height: 20
                        fillMode: Image.PreserveAspectFit
                    }

                    ColorOverlay {
                        anchors.fill: butIcon
                        source: butIcon
                        color: "#393e46"
                    }

                    Text {
                        font.weight: Font.Medium
                        horizontalAlignment: Text.AlignLeft
                        verticalAlignment: Text.AlignVCenter
                        width: parent.width
                        height: parent.height
                        color: "#26282a"
                        text: buttonText
                        anchors.left: parent.left
                        anchors.leftMargin: butIcon.width + 5
                        font.pointSize: 12
                        font.family: "Rubik"
                    }
                }
            }
            model: menuModel
            focus: true
            highlight: Rectangle {
                width: listView.width
                color: "#26a3e7fc"
                border.color: "transparent"
                Rectangle {
                    width: 4
                    height: 59
                    color: "#259fc4"
                    radius: 0
                    border.width: 0
                }

                Rectangle {
                    width: 10
                    color: "#259fc4"
                    radius: 5
                    anchors.left: parent.left
                    anchors.leftMargin: 0
                    anchors.bottom: parent.bottom
                    anchors.bottomMargin: 0
                    anchors.top: parent.top
                    anchors.topMargin: 0
                }
            }
        }

        GroupBox {
            id: titleGroup
            height: 123
            anchors.left: parent.left
            anchors.leftMargin: 0
            anchors.top: parent.top
            anchors.topMargin: 0
            anchors.right: parent.right
            anchors.rightMargin: 0
            background: Rectangle {
                color: "transparent"
                border.color: "transparent"
            }

            Text {
                id: title
                y: 9
                width: 84
                height: 81
                color: "#393e46"
                text: qsTr("Bank\nApp")
                anchors.horizontalCenterOffset: 46
                anchors.horizontalCenter: parent.horizontalCenter
                font.weight: Font.Bold
                font.family: "Rubik"
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignLeft
                font.pixelSize: 35
            }

            Image {
                id: titleIcon
                y: 7
                width: 77
                height: 83
                anchors.horizontalCenterOffset: -63
                anchors.horizontalCenter: parent.horizontalCenter
                source: "qrc:/resources/icons/landmark-solid.svg"
                sourceSize.width: 60
                sourceSize.height: 60
                fillMode: Image.PreserveAspectFit
            }
            ColorOverlay {
                anchors.fill: titleIcon
                source: titleIcon
                color: "#393e46"
            }

        }

        Button {
            id: logOutButton
            x: 8
            y: 75
            width: 234
            height: 40
            text: qsTr("Log Out")
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.left: parent.left
            anchors.leftMargin: 8
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 8
            font.weight: Font.Medium
            display: AbstractButton.TextOnly

            background: Rectangle {
                color: "transparent"
            }

            contentItem: Text {
                color: "#4c26282a"
                text: logOutButton.text
                font.pointSize: 10
                font.weight: Font.Medium
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
                font.family: "Rubik"
            }

            onClicked: {
                logOut();
            }
        }
    }
}



/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
