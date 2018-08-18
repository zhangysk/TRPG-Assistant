#include <QApplication>
#include <QWidget>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ptzs::MainWindow w;
    w.show();

    return a.exec();
}
