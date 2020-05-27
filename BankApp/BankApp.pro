 QT += quick

CONFIG += c++17

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Refer to the documentation for the
# deprecated API to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        controller/AdminScreenController.cpp \
        controller/LogInScreenController.cpp \
        controller/MainController.cpp \
        controller/UserScreenController.cpp \
        main.cpp \
        model/Account.cpp \
        model/Admin.cpp \
        model/Authorization.cpp \
        model/Bank.cpp \
        model/Card.cpp \
        model/Config.cpp \
        model/ChildAccount.cpp \
        model/CreditCard.cpp \
        model/DebitCard.cpp \
        model/FamillyAccount.cpp \
        model/Fund.cpp \
        model/History.cpp \
        model/JsonManager.cpp \
        model/LogInData.cpp \
        model/Payment.cpp \
        model/PaymentRetriever.cpp \
        model/RetirementFund.cpp \
        model/SavingsAccount.cpp \
        model/SavingsFund.cpp \
        model/Test.cpp \
        model/User.cpp

RESOURCES += \
    fonts.qrc \
    icons.qrc \
    qml_components.qrc \
    qml_screens.qrc \
    qml_tabs.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH = view/

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    controller/AdminScreenController.h \
    controller/IController.h \
    controller/LogInScreenController.h \
    controller/MainController.h \
    controller/UserScreenController.h \
    model/Account.h \
    model/Admin.h \
    model/Authorization.h \
    model/Bank.h \
    model/Card.h \
    model/Config.h \
    model/ChildAccount.h \
    model/CreditCard.h \
    model/DebitCard.h \
    model/FamillyAccount.h \
    model/Fund.h \
    model/History.h \
    model/IAccount.h \
    model/IUser.h \
    model/IValidator.h \
    model/JsonManager.h \
    model/LogInData.h \
    model/Payment.h \
    model/PaymentRetriever.h \
    model/Test.h \
    model/RetirementFund.h \
    model/SavingsAccount.h \
    model/SavingsFund.h \
    model/User.h \
    model/enums/AccountType.h \
    model/enums/CardType.h \
    model/enums/FundType.h \
    model/json.hpp

DISTFILES +=
