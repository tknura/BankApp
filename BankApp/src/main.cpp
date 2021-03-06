#include "controller/MainWindow.h"

#include "model/Bank.h"
#include "model/Authorization.h"
#include "model/JsonManager.h"
#include "model/RetirementFund.h"
#include <map>
#include <iostream>
#include <QApplication>

int main(int argc, char *argv[])
{
    Bank::Start();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
