import QtQuick 2.0
import QtQuick.Controls 2.13

Item {
    id: styledOutput
    objectName: "styledInput"
    visible: true
    width: parent
    height: 50
    
 
    
    Rectangle {
        anchors.fill: parent
        color: "#ececec"
        border.color: "#ececec"
        border.width: 2
        radius: 25
        
        Text {
            id: name
            width: 400
            height: 20
            color: "#393e46"

            anchors.top: parent.top
            anchors.topMargin: 5
            anchors.left: parent.left
            anchors.leftMargin: 20
            font.weight: Font.Medium
            font.family: "Rubik"
            verticalAlignment: Text.bottom
            font.pixelSize: 15
        }
        Text {
            id: goods
            width: 400
            height: 20
            color: "#ABB2B9"

            anchors.bottom : parent.bottom
            anchors.bottomMargin: 5
            anchors.left: parent.left
            anchors.leftMargin: 20
            font.weight: Font.Medium
            font.family: "Rubik"
            verticalAlignment: Text.bottom
            font.pixelSize: 13

            
        }
        Text {
            id: currencyLabel
            anchors {
                top: parent.top; bottom: parent.bottom
                right: parent.right; rightMargin: 25
            }
            verticalAlignment: Text.AlignVCenter
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
             
            text: "+20,00"
            font.pixelSize: 18
            verticalAlignment: Text.AlignVCenter


        }
    }
    



}
