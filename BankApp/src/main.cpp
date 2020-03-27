#include "controller/MainWindow.h"

#include "model/Bank.h"
#include "model/Authorization.h"
#include "model/JsonManager.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    Bank::Start();
    JsonManager test(3);
   // test.ParseFriendsData();
    test.ParseAccountData();
    return 0;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
