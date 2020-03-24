QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
<<<<<<< HEAD:BankApp/BankApp.pro
    Account.cpp \
    Admin.cpp \
    Authorization.cpp \
    Bank.cpp \
    Config.cpp \
    Fund.cpp \
    JsonManager.cpp \
    LogInData.cpp \
    Payment.cpp \
    PaymentRetriever.cpp \
    User.cpp \
=======
    controller/MainWindow.cpp \
>>>>>>> 61c719dcdaa1a8d55f88597da010f3dca956e01f:BankApp/src/BankApp.pro
    main.cpp \
    model/Account.cpp \
    model/Admin.cpp \
    model/Authorization.cpp \
    model/Bank.cpp \
    model/Fund.cpp \
    model/IUser.cpp \
    model/JsonManager.cpp \
    model/LogInData.cpp \
    model/Payment.cpp \
    model/PaymentRetriever.cpp \
    model/User.cpp \

HEADERS += \
<<<<<<< HEAD:BankApp/BankApp.pro
    Account.h \
    Admin.h \
    Authorization.h \
    Bank.h \
    Config.h \
    Fund.h \
    IUser.h \
    IValidator.h \
    JsonManager.h \
    LogInData.h \
    Payment.h \
    PaymentRetriever.h \
    User.h \
    mainwindow.h
=======
    controller/MainWindow.h \
    model/Account.h \
    model/Admin.h \
    model/Authorization.h \
    model/Bank.h \
    model/Fund.h \
    model/IUser.h \
    model/IValidator.h \
    model/JsonManager.h \
    model/LogInData.h \
    model/Payment.h \
    model/PaymentRetriever.h \
    model/User.h \
>>>>>>> 61c719dcdaa1a8d55f88597da010f3dca956e01f:BankApp/src/BankApp.pro

FORMS += \
    view/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
<<<<<<< HEAD:BankApp/BankApp.pro
    config.txt
=======
    model/BankApp.pro.user
>>>>>>> 61c719dcdaa1a8d55f88597da010f3dca956e01f:BankApp/src/BankApp.pro
