#include <QApplication>
#include <QWidget>
#include "mainwindow.h"
#include "script.h"
#include "data.h"

QFont myFont;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ptzs::MainWindow w;
    w.show();

    return a.exec();
}
