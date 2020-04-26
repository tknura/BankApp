import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.3
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.3

Window {
    id: main
    minimumWidth: 700
    minimumHeight: 400
    visible: true
    width: 1000
    height: 700
    color: "#eeeeee"
    title: "BankApp"

    function loadUserScreen() {
        stackView.replace(userScreen)
    }

    function loadAdminScreen() {
        stackView.replace(adminScreen)
    }

    StackView {
        id: stackView
        anchors.fill: parent
        replaceEnter: Transition {
                PropertyAnimation {
                    property: "opacity"
                    from: 0
                    to:1
                    duration: 200
                }
            }
        replaceExit: Transition {
            PropertyAnimation {
                property: "opacity"
                from: 1
                to:0
                duration: 200
            }
        }

        LoginScreen{
            id: loginScreen
        }

        UserScreen{
            visible: false
            id: userScreen
        }

        AdminScreen {
            visible: false
            id: adminScreen
        }

    }
}







/*##^##
Designer {
    D{i:1;anchors_height:700;anchors_width:1000}
}
##^##*/
