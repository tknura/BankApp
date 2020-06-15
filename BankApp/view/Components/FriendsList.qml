import QtQuick 2.0
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3
import QtQml.Models 2.2
import FriendsList 1.0
Item {

    signal buttonPressed(string friendName, string accNum, string address)

    id:friends
    objectName: "friendsList"
    visible: true
    width: 500
    height: 86

    function reload(){
        friendsmodel.clear();
        friendsmodel.update();
    }

    FriendsListModel{
        id:friendsmodel
    }

    Text {
        id: title
        x: 0
        y: 33
        width: 99
        height: 25
        color: "#393e46"
        text: "Friends"
        font.family: "Rubik"
        anchors.leftMargin: 22
        font.weight: Font.Medium
        anchors.left: parent.left
        font.pixelSize: 20
        verticalAlignment: Text.AlignVCenter
        anchors.top: parent.top
        anchors.topMargin: 0
    }

    Frame {
        padding: 0
        anchors.top: title.bottom
        anchors.right: parent.right
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.topMargin: 10
        background: Rectangle{
            color: "transparent"
            border.color: "transparent"
        }

        ListView {
            id: list
            anchors.bottomMargin: 10
            anchors.topMargin: 0
            clip: true
            anchors.fill: parent
            model: friendsmodel
            orientation: ListView.Horizontal
            ScrollBar.horizontal : ScrollBar {
            y: 40}
            spacing: 7
            delegate: Button {
                id: button
                width: 150
                height: 40
                Text{
                    id: name
                    anchors.fill: parent
                    font.pixelSize: 15
                    font.family: "Rubik"
                    font.weight: Font.Medium
                    color: "#9b9b9b"
                    text: model.name
                    verticalAlignment: Text.AlignVCenter
                    horizontalAlignment: Text.AlignHCenter
                }
                background: Rectangle {
                    id: background
                    anchors.fill: parent
                    color: button.pressed ? "#EEEEEE" : button.hovered ? "#F7F7F7" : "#ffffff"
                    radius: 25
                }
                onClicked: {
                    buttonPressed(model.name, model.accNum, model.address);
                }
            }
        }
    }

}
