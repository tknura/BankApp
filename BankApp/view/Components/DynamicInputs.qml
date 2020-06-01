import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3

Column {
    id: root
    width: parent.width
    spacing: parent.spacing

    function addTextInput(title, placeholder, inputMask) {
        var component;
        var sprite;
        component = Qt.createComponent("qrc:/components/StyledInput.qml");
        sprite = component.createObject(root,
                                        {
                                           width: root.width,
                                           titleText: title,
                                           placeholder: placeholder,
                                           inputMask: inputMask
                                        });
    }

    function addCurrencyInput(title) {
        var component;
        var sprite;
        component = Qt.createComponent("qrc:/components/StyledCurrencyInput.qml");
        sprite = component.createObject(root,
                                        {
                                           width: root.width,
                                           titleText: title
                                        });
    }

    function addCombo(title, objectName, model) {
        var component;
        var sprite;
        component = Qt.createComponent("qrc:/components/StyledCombo.qml");
        sprite = component.createObject(root,
                                        {
                                           width: root.width,
                                           titleText: title,
                                           objectName: objectName,
                                           model: model
                                        });
    }

    function addDateInput(title) {
        var component;
        var sprite;
        component = Qt.createComponent("qrc:/components/StyledDateInput.qml");
        sprite = component.createObject(dynamicInputs,
                                        {
                                           width: dynamicInputs.width,
                                           titleText: title
                                        });
    }

    function removeDynamicInputs() {
        for(var i = 0; i < root.children.length; ++i) {
            root.children[i].destroy(0);
        }
    }
}



