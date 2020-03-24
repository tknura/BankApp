#include "controller\MainWindow.h"

#include "model\Bank.h"

#include <QApplication>

int main(int argc, char *argv[])
{
   // Bank::currentlyLoggedUser = new User(1);
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
