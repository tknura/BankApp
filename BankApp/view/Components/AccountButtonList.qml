import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3
import QtGraphicalEffects 1.12
import AccountButtonModel 1.0
import QtQuick.Layouts 1.3

Item {
    id: element
    objectName: "accountButtonList"
    height: 200
    property string checkedAccNumber
    property alias model: list.model
    signal updateNum(string accNumber)

    function reload(){
       var tmp = checkedAccNumber
       model.clear();
       model.update();
        for(var child in list.contentItem.children) {
            if(list.contentItem.children[child].accNumberText == tmp) {
                list.contentItem.children[child].checked = true;
            }
        }
    }

    visible: true
    onUpdateNum: {
        checkedAccNumber = accNumber
    }
    ListView {
        id: list
        clip: true
        implicitHeight: 300
        width: parent.width
        anchors.rightMargin: 0
        anchors.bottomMargin: 0
        anchors.leftMargin: 0
        anchors.topMargin: 0
        leftMargin: 10
        spacing: 10
        orientation: ListView.Horizontal
        anchors.fill: parent
        model: AccountButtonModel {}
        ScrollBar.horizontal : ScrollBar {}

        delegate: AccountButton {
           y: 10
           accTypeText: model.type
           accCurrencyText: model.currency
           accNumberText: model.number
           accAmountText: model.amount.toFixed(2)
           itemToRefresh: element
           buttongroup: accountButtons
       }
        Component.onCompleted: {
            list.contentItem.children[0].checked = true;
        }
    }

    ButtonGroup { id: accountButtons }
}

