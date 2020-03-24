#include "controller\MainWindow.h"
#include "ui_mainwindow.h"
#include <QDesktopServices>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked() {
    QDesktopServices::openUrl(QUrl("http://twoja-stara.pl/", QUrl::TolerantMode));
}
