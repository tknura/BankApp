import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

Item {
    id: styledInputList
    objectName: "styledInputList"
    visible: true
    width: 640
    height: 80

    property string titleText: "Title"
    //property alias backgroundColor: rectangle.color
    property alias model: list.model
    property list<Text> resultList

    function clear() {
        for(var child in list.contentItem.children) {
            child.checked = false;
        }
    }

    function updateResult() {
        for(var child in list.contentItem.children) {
            if(child.checked){
                resultList.push(child.text);
            }
        }
    }

    function clearResult() {
        for(var item in resultList) {
            resultList.pop();
        }
    }

    ListView {
        id: list
        clip: true
        anchors.top: parent.top
        anchors.topMargin: 31
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 0
        anchors.left: parent.left
        anchors.leftMargin: 0
        anchors.right: parent.right
        anchors.rightMargin: 0
        ScrollBar.vertical: ScrollBar {
             width: 10
             anchors.left: parent.righ
             policy: ScrollBar.AlwaysOn
         }
        delegate: CheckDelegate {
                   id: dlgt
                   text: modelData
                   width: list.width - 15
                   background: Rectangle {
                            radius: 20
                            color: dlgt.hovered ? "#a3e7fc" : "#F7F7F7";
                            anchors.left: dlgt.left
                            anchors.leftMargin: 0
                            width: dlgt.width
                   }
                   onCheckedChanged: {
                       if(checked){
                            resultList.push(modelData);
                       }
                       else {
                            clearResult();
                            updateResult();
                       }
                   }
        }
    }

//    Rectangle {
//        id: rectangle
//        color: "#ffffff"
//        anchors.top: parent.top
//        anchors.topMargin: 0
//        anchors.right: parent.right
//        anchors.rightMargin: 0
//        anchors.left: parent.left
//        anchors.leftMargin: 0
//        anchors.bottom: list.top
//        anchors.bottomMargin: 0
//    }

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
}

/*##^##
Designer {
    D{i:1;anchors_height:49;anchors_width:640;anchors_x:0;anchors_y:31}
}
##^##*/
