import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3
import QtGraphicalEffects 1.12

Item {
    id: element
    height: 180
    property var itemToRefresh

    function addButton(p_accTypText, p_accNumberText, p_accAmountText, p_accCurencyText,
                       p_isDisabled) {
        var component;
        var sprite;
        component = Qt.createComponent("AccountButton.qml");
        sprite = component.createObject(row,
                                        {
                                            accTypeText: p_accTypText,
                                            accNumberText: p_accNumberText,
                                            accAmountText: p_accAmountText,
                                            accCurrencyText: p_accCurencyText,
                                            isDisabled: p_isDisabled,
                                            buttongroup: accountButtons,
                                            itemToRefresh: itemToRefresh
                                        });
    }

    ScrollView {
        id: scrollView
        anchors.fill: parent

        Row {
            id: row
            anchors.fill: parent
            spacing: 10
            layoutDirection: Qt.LeftToRight
        }
    }

    ButtonGroup { id: accountButtons }
}

