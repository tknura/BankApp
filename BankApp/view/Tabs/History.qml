import QtQuick 2.0
import QtQuick.Controls 2.3
import QtQuick.Layouts 1.3
import HistoryList 1.0
import components 1.0
import QtQml.Models 2.2

Item {
    objectName: "history"
    id: history
    visible: true
    width: 700
    height: 700

    signal refresh()
    onRefresh: {
        histmodel.clear();
        histmodel.update(accountsList.checkedAccNumber);
        accountsList.reload();
    }

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
        id: accounts
        x: 70
        y: 156
        width: 247
        height: 57
        text: qsTr("Accounts")
        font.weight: Font.Medium
        anchors.topMargin: 156
        anchors.leftMargin: 70
        anchors.top: parent.top
        anchors.left: parent.left
        font.family: "Rubik"
        font.pixelSize: 30
        verticalAlignment: Text.AlignVCenter
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
        height: 168
        anchors.right: parent.right
        anchors.rightMargin: 48
        anchors.left: parent.left
        anchors.leftMargin: 70
        anchors.top: accounts.bottom
        anchors.topMargin: 0

        onCheckedAccNumberChanged: {
            histmodel.clear();
            histmodel.update(accountsList.checkedAccNumber);
        }
    }


    Frame {
        padding: 0
        anchors.topMargin: 0
        anchors.bottomMargin: 55
        background: Rectangle{
            color: "transparent"
            border.color: "transparent"
        }
        anchors.top: accounts1.bottom
        anchors.left: accountsList.left
        anchors.right: accountsList.right
        anchors.bottom: parent.bottom

        ListView {
            clip: true
            implicitHeight: 300
            anchors.fill: parent
            model: histmodel
            ScrollBar.vertical: ScrollBar { }

            delegate: HistoryBar {
                width: parent.width
                nametext: model.name
                namegoods: model.description
                nameamount: (model.amount < 0 ? "" : " +") + model.amount.toFixed(2)
                namedate: model.date
                coloramount: model.amount < 0 ? "#FF0000" : "#259fc4"
                currencycolor: model.amount < 0 ? "#FF0000" : "#259fc4"
            }
        }
    }

    Text {
        id: accounts1
        x: 79
        y: 152
        width: 247
        height: 57
        text: qsTr("Transactions")
        font.weight: Font.Medium
        anchors.topMargin: 391
        anchors.leftMargin: 70
        anchors.top: parent.top
        anchors.left: parent.left
        font.family: "Rubik"
        font.pixelSize: 30
        verticalAlignment: Text.AlignVCenter
    }

}


/*##^##
Designer {
    D{i:7;anchors_height:254}
}
##^##*/
