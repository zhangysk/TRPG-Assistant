#include "editarea.h"
#include "treewidget.h"

using namespace ptzs;

EditArea::EditArea(QWidget *parent) : QFrame(parent)
{
    setMinimumSize(985,608);

    background=new ClickableLabel(this);
    info=new ClickableLabel(this);
    npc=new ClickableLabel(this);
    scene=new ClickableLabel(this);
    file=new ClickableLabel(this);
    st=File;

    file->setPixmap(QPixmap(":/tag10.png"));
    info->setPixmap(QPixmap(":/tag21.png"));
    npc->setPixmap(QPixmap(":/tag31.png"));
    scene->setPixmap(QPixmap(":/tag41.png"));
    background->setPixmap(QPixmap(":/background.png"));

    background->setCursor(Qt::ArrowCursor);
    file->setScaledContents(true);
    info->setScaledContents(true);
    npc->setScaledContents(true);
    scene->setScaledContents(true);
    background->setScaledContents(true);
    connect(file,SIGNAL(clicked(ClickableLabel*)),this,SLOT(changeState(ClickableLabel*)));
    connect(info,SIGNAL(clicked(ClickableLabel*)),this,SLOT(changeState(ClickableLabel*)));
    connect(npc,SIGNAL(clicked(ClickableLabel*)),this,SLOT(changeState(ClickableLabel*)));
    connect(scene,SIGNAL(clicked(ClickableLabel*)),this,SLOT(changeState(ClickableLabel*)));
}

void EditArea::resizeEvent(QResizeEvent *ev)
{
    qDebug()<<"asdfa";
    int x,y,w,h;
    if((float)width()/height()>1.62)
    {
        qDebug()<<"asdfa";
        y=0;
        h=height();
        w=1.62*height();
        x=(width()-w)/2;
    }
    else
    {
        qDebug()<<"asasdaa";
        x=0;
        w=width();
        h=w/1.62;
        y=(height()-h)/2;
    }
    switch(st)
    {
    case File:
        file->setGeometry(x+0.05*w,y+0.09*h,w*0.09,h*0.06);
        info->setGeometry(x+0.02*w,y+0.18*h,w*0.09,h*0.06);
        npc->setGeometry(x+0.02*w,y+0.27*h,w*0.09,h*0.06);
        scene->setGeometry(x+0.02*w,y+0.36*h,w*0.09,h*0.06);
        break;
    case Info:
        file->setGeometry(x+0.02*w,y+0.09*h,w*0.09,h*0.06);
        info->setGeometry(x+0.05*w,y+0.18*h,w*0.09,h*0.06);
        npc->setGeometry(x+0.02*w,y+0.27*h,w*0.09,h*0.06);
        scene->setGeometry(x+0.02*w,y+0.36*h,w*0.09,h*0.06);
        break;
    case Npc:
        file->setGeometry(x+0.02*w,y+0.09*h,w*0.09,h*0.06);
        info->setGeometry(x+0.02*w,y+0.18*h,w*0.09,h*0.06);
        npc->setGeometry(x+0.05*w,y+0.27*h,w*0.09,h*0.06);
        scene->setGeometry(x+0.02*w,y+0.36*h,w*0.09,h*0.06);
        break;
    default:
        file->setGeometry(x+0.02*w,y+0.09*h,w*0.09,h*0.06);
        info->setGeometry(x+0.02*w,y+0.18*h,w*0.09,h*0.06);
        npc->setGeometry(x+0.02*w,y+0.27*h,w*0.09,h*0.06);
        scene->setGeometry(x+0.05*w,y+0.36*h,w*0.09,h*0.06);
        break;
    }
    background->setGeometry(x+0.05*w,y,0.95*w,h);
}

void EditArea::changeState(ClickableLabel *p)
{
    if(p==file&&st!=File)
    {
        st=File;
        file->setPixmap(QPixmap(":/tag10.png"));
        info->setPixmap(QPixmap(":/tag21.png"));
        npc->setPixmap(QPixmap(":/tag31.png"));
        scene->setPixmap(QPixmap(":/tag41.png"));
        resizeEvent(nullptr);
    }
    else if(p==info&&st!=Info)
    {
        st=Info;
        file->setPixmap(QPixmap(":/tag11.png"));
        info->setPixmap(QPixmap(":/tag20.png"));
        npc->setPixmap(QPixmap(":/tag31.png"));
        scene->setPixmap(QPixmap(":/tag41.png"));
        resizeEvent(nullptr);
    }
    else if(p==npc&&st!=Npc)
    {
        st=Npc;
        file->setPixmap(QPixmap(":/tag11.png"));
        info->setPixmap(QPixmap(":/tag21.png"));
        npc->setPixmap(QPixmap(":/tag30.png"));
        scene->setPixmap(QPixmap(":/tag41.png"));
        resizeEvent(nullptr);
    }
    else if(p==scene&&st!=Scene)
    {
        st=Scene;
        file->setPixmap(QPixmap(":/tag11.png"));
        info->setPixmap(QPixmap(":/tag21.png"));
        npc->setPixmap(QPixmap(":/tag31.png"));
        scene->setPixmap(QPixmap(":/tag40.png"));
        resizeEvent(nullptr);
    }
}
