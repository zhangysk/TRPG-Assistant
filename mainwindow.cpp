#include "mainwindow.h"

using namespace ptzs;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    tabWidget=new TabWidget;
    setCentralWidget(tabWidget);
    file=new QMenu("文件");
    edit=new QMenu("编辑");
    help=new QMenu("帮助");
    openAction=new QAction(QIcon(":/open.png"),"打开...",this);
    newAction=new QAction(QIcon(":/new.png"),"新建",this);
    saveAction=new QAction(QIcon(":/save.png"),"保存",this);
    menuBar()->addMenu(file);
    menuBar()->addMenu(edit);
    menuBar()->addMenu(help);
    file->addAction(openAction);
    file->addAction(newAction);
    file->addAction(saveAction);
}
