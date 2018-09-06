#include "mainwindow.h"

using namespace ptzs;

MainWindow::MainWindow(QWidget *parent) : QWidget(parent)
{
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(QPixmap(":/armstrong_1.png")));

    setAutoFillBackground(true);
    setPalette(palette);

    close=new ClickableLabel;
    minimize=new ClickableLabel;
    maximize=new ClickableLabel;
    editArea=new EditArea(this);

    editArea->setSizePolicy(QSizePolicy::MinimumExpanding,QSizePolicy::MinimumExpanding);
    setWindowFlags(Qt::FramelessWindowHint);

    close->setPixmap(QPixmap(":/close.png"));
    close->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);
    minimize->setPixmap(QPixmap(":/close.png"));
    minimize->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);
    maximize->setPixmap(QPixmap(":/close.png"));
    maximize->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);

    layout=new QGridLayout(this);
    layout->addWidget(close,0,3,Qt::AlignRight);
    layout->addWidget(minimize,0,1,Qt::AlignRight);
    layout->addWidget(maximize,0,2,Qt::AlignRight);
    layout->setColumnStretch(0,1);
    layout->addWidget(editArea,1,0,1,4,Qt::AlignCenter);
    connect(close,SIGNAL(clicked(ClickableLabel*)),this,SLOT(close()));
    connect(minimize,SIGNAL(clicked(ClickableLabel*)),this,SLOT(showMinimized()));
    connect(maximize,SIGNAL(clicked(ClickableLabel*)),this,SLOT(maximizing()));
}

void MainWindow::resizeEvent(QResizeEvent *ev)
{
    editArea->resize(width(),height()-close->height());
    editArea->move(0,close->height());
}

void MainWindow::paintEvent(QPaintEvent *event)
{

}

void MainWindow::maximizing()
{
    if(isMaximized())
        showNormal();
    else
        showMaximized();
}

