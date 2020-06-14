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
    height: 70
    FriendsListModel{
        id:friendsmodel
    }

    Frame {
        background: Rectangle{
            color: "transparent"
            border.color: "transparent"
        }
       anchors.fill: parent

        ListView {
            id: list
            clip: true
            anchors.fill: parent
            model: friendsmodel
            orientation: ListView.Horizontal
            ScrollBar.horizontal : ScrollBar {}
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
