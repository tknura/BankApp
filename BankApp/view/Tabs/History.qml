import QtQuick 2.0
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3
import HistoryList 1.0
import components 1.0
import QtQml.Models 2.2

Item {
   // property var historyList: HistoryList
    objectName: "history"
    id: history
    visible: true
    width: 700
    height: 700

    HistoryListModel {
        id:histmodel
    }

    Rectangle {
        id: background
        color: "#eeeeee"
        width: parent.width
        border.width: 0
        border.color: "#eeeeee"
        anchors.right: parent.right
        anchors.rightMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.top: parent.top
        anchors.topMargin: 0
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0

         }

        Text {
            id: title
            x: 70
            y: 50
            width: 328
            height: 75
            color: "#26282a"
            text: qsTr("History")
            font.weight: Font.Bold
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignLeft
            font.pixelSize: 60
            font.family: "Rubik"
        }

        Text {
            id: desc
            x: 70
            y: 123
            width: 309
            height: 25
            color: "#4c26282a"
            text: qsTr("Look into your past transactions")
            font.pixelSize: 18
            font.family: "Rubik"
        }
        AccountButtonList {
            id: accountsList
            height: 160
            anchors.right: parent.right
            anchors.rightMargin: 48
            anchors.left: parent.left
            anchors.leftMargin: 70
            anchors.top: desc.bottom
            anchors.topMargin: 6
            //itemToRefresh: history
            onCheckedAccNumberChanged: {
                console.log(checkedAccNumber);
            }
        }
        Button{//ten przycisk jest do wywalenia, w przypadku kliknięcia zmiany konta ma sie uruchamiać funkcja clear i update
            id: dest
            anchors.bottom: parent.bottom
            anchors.right: parent.right
            width: 100
            height: 100
            text: "Refresh"

            onClicked:{
                histmodel.clear()
                histmodel.update("55533333")
            }

        }


        Frame {
            background: Rectangle{
                color: "transparent"
                border.color: "transparent"
            }

            width: parent.width
            anchors.top: accountsList.bottom
            anchors.left: accountsList.left
            anchors.right: accountsList.right
            anchors.bottom: background.bottom

            ListView {
                clip: true
                implicitHeight: 300
                width: parent.width
                anchors.fill: parent
                model: histmodel

                delegate: RowLayout {
                    width: parent.width
                    HistoryBar {
                        nametext: model.name
                        namegoods: model.description
                        nameamount: model.amount
                        namedate: model.date
                   }


                }

            }
        }
    }

