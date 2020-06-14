import QtQuick 2.0
import QtQuick.Controls 2.13

Item {
    id: historyBar
    objectName: "historyBar"
    visible: true
    width: 500
    height: 60

    property alias nametext: name.text
    property alias namegoods: goods.text
    property alias nameamount: amount.text
    property alias namedate: date.text
    property alias coloramount: amount.color
    property alias currencycolor: currencyLabel.color
    
    Rectangle {
        id: kwadrat
        height: 50
        anchors.top: parent.top
        anchors.topMargin: 5
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 5
        anchors.right: parent.right
        anchors.left: parent.left
        color: "#ffffff"
        border.color: "#ffffff"
        border.width: 2
        radius: 25
        
        Text {
            id: name
            width: 200
            height: 20
            color: "#393e46"
            text: "Unknown"
            anchors.top: parent.top
            anchors.topMargin: 5
            anchors.left: parent.left
            anchors.leftMargin: 20
            font.weight: Font.Medium
            font.family: "Rubik"
            font.pixelSize: 15
        }
        Text {
            id: goods
            width: 200
            height: 20
            color: "#ABB2B9"
            text: "Unknown"
            anchors.bottom : parent.bottom
            anchors.bottomMargin: 5
            anchors.left: parent.left
            anchors.leftMargin: 20
            font.weight: Font.Medium
            font.family: "Rubik"
            font.pixelSize: 13

            
        }
        Text {
            id: date
            anchors.centerIn: kwadrat
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 16
            text:"0000-00-00"
            color: "#ABB2B9"
        }

        Text {
            id: currencyLabel
            anchors {
                top: kwadrat.top; bottom: kwadrat.bottom
                right: kwadrat.right; rightMargin: 25
            }
            verticalAlignment: Text.AlignVCenter
            font.weight: Font.Bold
            color: "#259fc4"
            text: qsTr("PLN")
            font.pixelSize: 18
        }
        Text {
            id: amount
            anchors {
                top: parent.top; bottom: parent.bottom
                right: currencyLabel.left

            }
            color: "#259fc4"
            text: "+00,00"
            font.pixelSize: 18
            verticalAlignment: Text.AlignVCenter


        }
    }
    



}
