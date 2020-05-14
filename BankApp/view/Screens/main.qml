import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.3

Window {
    id: main
    objectName: "main"
    minimumWidth: 700
    minimumHeight: 400
    visible: true
    width: 1000
    height: 700
    color: "#eeeeee"
    title: "BankApp"

    LoginScreen{
        id: loginScreen
        anchors.fill: parent
    }

    FontLoader { id: rubikRegular; source: "/resources/fonts/Rubik-Regular.ttf" }
    FontLoader { id: rubikMedium; source: "/resources/fonts/Rubik-Medium.ttf" }
    FontLoader { id: rubikBold; source: "/resources/fonts/Rubik-Bold.ttf" }

    function loadUserScreen() {
        stackView.replace(["qrc:/view/Screens/UserScreen.qml"])
    }

    function loadAdminScreen() {
        stackView.replace(["qrc:/view/Screens/AdminScreen.qml"])
    }

    StackView {
        id: stackView
        anchors.fill: parent
        initialItem: loginScreen
        replaceEnter: Transition {
            PropertyAnimation {
                property: "opacity"
                from: 0
                to:1
                duration: 300
            }
        }
        replaceExit: Transition {
            PropertyAnimation {
                property: "opacity"
                from: 1
                to:0
                duration: 300
            }
        }
    }

}
