#include "controller/MainWindow.h"

#include "model/Bank.h"
#include "model/Authorization.h"
#include "model/JsonManager.h"
#include "model/Test.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    Bank::Start();
    Test::Run();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
