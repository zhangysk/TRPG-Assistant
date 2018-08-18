#include "mainwindow.h"

using namespace ptzs;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    tabWidget=new TabWidget;
    this->setCentralWidget(tabWidget);
}
