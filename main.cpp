#include <QApplication>
#include <QWidget>
#include "mainwindow.h"
#include "data.h"

QFont myFont;
ptzs::Script script;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ptzs::MainWindow w;
    w.show();

    return a.exec();
}
