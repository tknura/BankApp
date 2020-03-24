<<<<<<< HEAD:BankApp/main.cpp
#include "mainwindow.h"
#include "Config.h"
=======
#include "controller\MainWindow.h"
>>>>>>> 61c719dcdaa1a8d55f88597da010f3dca956e01f:BankApp/src/main.cpp

#include <iostream>
#include <QApplication>

int main(int argc, char *argv[])
{
    try
    {
         Config test;
    }
    catch (std::ifstream::failure &e)
    {
        std::cout<<e.what();
    }
    return 0;
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
