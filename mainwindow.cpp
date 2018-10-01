#include "mainwindow.h"

using namespace ptzs;

MainWindow::MainWindow(QWidget *parent) : QFrame(parent)
{
    QPalette palette;
    background.load(":png/armstrong_1.png");
    setAutoFillBackground(true);

    int i=QFontDatabase::addApplicationFont(":/font/HYZhuZiHeiMoFaW.ttf");
    QString n = QFontDatabase::applicationFontFamilies(i).at(0);
    myFont.setPixelSize(20);
    myFont.setFamily(n);
    palette.setBrush(QPalette::Background,QBrush(background.scaled(size(),Qt::KeepAspectRatioByExpanding)));
    setPalette(palette);
    setStyleSheet(QString::fromUtf8("border:1px solid red"));

    close=new ClickableLabel;
    minimize=new ClickableLabel;
    maximize=new ClickableLabel;
    editArea=new EditArea(this);
    border[Border::top]=new Border(Border::top,this);
    border[Border::left]=new Border(Border::left,this);
    border[Border::right]=new Border(Border::right,this);
    border[Border::bottom]=new Border(Border::bottom,this);
    border[Border::topLeft]=new Border(Border::topLeft,this);
    border[Border::topRight]=new Border(Border::topRight,this);
    border[Border::bottomLeft]=new Border(Border::bottomLeft,this);
    border[Border::bottomRight]=new Border(Border::bottomRight,this);
    save=new ClickableLabel(this);

    editArea->setSizePolicy(QSizePolicy::MinimumExpanding,QSizePolicy::MinimumExpanding);

    setWindowFlags(Qt::FramelessWindowHint);

    save->setPixmap(QPixmap("qrc:/png/save.png"));
    close->setPixmap(QPixmap(":png/close.png"));
    close->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);
    minimize->setPixmap(QPixmap(":png/close.png"));
    minimize->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);
    maximize->setPixmap(QPixmap(":png/close.png"));
    maximize->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);

    layout=new QGridLayout(this);
    layout->setMargin(0);
    layout->addWidget(border[Border::topLeft],0,0,1,1);
    layout->addWidget(border[Border::topRight],0,5,1,1);
    layout->addWidget(border[Border::bottomLeft],3,0,1,1);
    layout->addWidget(border[Border::bottomRight],3,5,1,1);
    layout->addWidget(border[Border::top],0,1,1,4);
    layout->addWidget(border[Border::left],1,0,2,1);
    layout->addWidget(border[Border::right],1,5,2,1);
    layout->addWidget(border[Border::bottom],3,1,1,4);
    layout->addWidget(border[Border::topLeft],0,0);
    layout->addWidget(save,1,1,Qt::AlignLeft);
    layout->addWidget(minimize,1,2,Qt::AlignRight);
    layout->addWidget(maximize,1,3,Qt::AlignRight);
    layout->addWidget(close,1,4,Qt::AlignRight);
    layout->addWidget(editArea,2,1,1,4,Qt::AlignCenter);
    layout->setColumnStretch(1,1);

    connect(close,SIGNAL(clicked(ClickableLabel*)),this,SLOT(close()));
    connect(minimize,SIGNAL(clicked(ClickableLabel*)),this,SLOT(showMinimized()));
    connect(maximize,SIGNAL(clicked(ClickableLabel*)),this,SLOT(maximizing()));
    setMinimumSize(909,680);
}

void MainWindow::resizeEvent(QResizeEvent *ev)
{
    editArea->resize(width(),height()-close->height());
    editArea->move(0,close->height());
    QPalette palette;
    palette.setBrush(QPalette::Background,QBrush(background.scaled(size(),Qt::KeepAspectRatioByExpanding)));
    setPalette(palette);
}

void MainWindow::paintEvent(QPaintEvent *event)
{

}

void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    if((ev->button()==Qt::LeftButton)&&!isMaximized())
    {
        startPos=ev->globalPos();
    }
}

void MainWindow::mouseMoveEvent(QMouseEvent *ev)
{
    if(ev->x()>2&&ev->x()<width()-2&&ev->y()>2&&ev->y()<close->height())
    {
        move(pos()+ev->globalPos()-startPos);
        startPos=ev->globalPos();
    }
}


void MainWindow::maximizing()
{
    if(isMaximized())
        showNormal();
    else
        showMaximized();
}

