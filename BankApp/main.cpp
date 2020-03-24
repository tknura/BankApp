#include "mainwindow.h"
#include "Config.h"

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
