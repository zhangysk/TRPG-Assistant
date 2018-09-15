#include "editarea.h"

using namespace ptzs;

EditArea::EditArea(QWidget *parent) : QFrame(parent)
{
    setMinimumSize(900,600);
    background=new ClickableLabel(this);
    info=new ClickableLabel(this);
    npc=new ClickableLabel(this);
    scene=new ClickableLabel(this);
    file=new ClickableLabel(this);
    widget=new QStackedWidget(this);
    st=File;

    widget->addWidget(new FileWidget(widget));
    widget->addWidget(new InfoWidget(widget));
    widget->addWidget(new NpcWidget(widget));
    widget->addWidget(new SceneWidget(widget));
    widget->addWidget(new SummaryEditor(widget));
    widget->addWidget(new AnnouncementEditor(widget));
    widget->addWidget(new MultipleDisplayer(MultipleDisplayer::map,widget));
    widget->addWidget(new MultipleDisplayer(MultipleDisplayer::normalNpc,widget));
    widget->addWidget(new MultipleDisplayer(MultipleDisplayer::keyNpc,widget));
    widget->addWidget(new MultipleDisplayer(MultipleDisplayer::normalScene,widget));
    widget->addWidget(new MultipleDisplayer(MultipleDisplayer::battleScene,widget));

    file->setPixmap(QPixmap(":png/tag10.png"));
    info->setPixmap(QPixmap(":png/tag21.png"));
    npc->setPixmap(QPixmap(":png/tag31.png"));
    scene->setPixmap(QPixmap(":png/tag41.png"));
    background->setPixmap(QPixmap(":png/background.png"));

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
    connect(((FileWidget*)widget->widget(0))->openLabel(),SIGNAL(clicked(ClickableLabel*)),this,SLOT(openFile()));
    connect(((FileWidget*)widget->widget(0))->newLabel(),SIGNAL(clicked(ClickableLabel*)),this,SLOT(newFile()));
    connect(((InfoWidget*)widget->widget(1))->summaryLabel(),SIGNAL(clicked(ClickableLabel*)),this,SLOT(summary()));
    connect(((InfoWidget*)widget->widget(1))->announcementLabel(),SIGNAL(clicked(ClickableLabel*)),this,SLOT(announcement()));
    connect(((InfoWidget*)widget->widget(1))->mapLabel(),SIGNAL(clicked(ClickableLabel*)),this,SLOT(map()));
    connect(((NpcWidget*)widget->widget(2))->normalNpcLabel(),SIGNAL(clicked(ClickableLabel*)),this,SLOT(normalNpc()));
    connect(((NpcWidget*)widget->widget(2))->keyNpcLabel(),SIGNAL(clicked(ClickableLabel*)),this,SLOT(keyNpc()));
    connect(((SceneWidget*)widget->widget(3))->normalSceneLabel(),SIGNAL(clicked(ClickableLabel*)),this,SLOT(normalScene()));
    connect(((SceneWidget*)widget->widget(3))->battleSceneLabel(),SIGNAL(clicked(ClickableLabel*)),this,SLOT(battleScene()));

}

void EditArea::resizeEvent(QResizeEvent*)
{
    int x,y,w,h;
    if((float)width()/height()>1.62)
    {
        y=0;
        h=height();
        w=1.62*height();
        x=(width()-w)/2;
    }
    else
    {
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
    widget->setGeometry(x+0.14*w,y+0.17*h,0.8*w,h*0.66);
}

void EditArea::changeState(ClickableLabel *p)
{
    if(p==file&&st!=File)
    {
        st=File;
        file->setPixmap(QPixmap(":png/tag10.png"));
        info->setPixmap(QPixmap(":png/tag21.png"));
        npc->setPixmap(QPixmap(":png/tag31.png"));
        scene->setPixmap(QPixmap(":png/tag41.png"));
        widget->setCurrentIndex(0);
        resizeEvent(nullptr);
    }
    else if(p==info&&st!=Info)
    {
        st=Info;
        file->setPixmap(QPixmap(":png/tag11.png"));
        info->setPixmap(QPixmap(":png/tag20.png"));
        npc->setPixmap(QPixmap(":png/tag31.png"));
        scene->setPixmap(QPixmap(":png/tag41.png"));
        widget->setCurrentIndex(1);
        resizeEvent(nullptr);
    }
    else if(p==npc&&st!=Npc)
    {
        st=Npc;
        file->setPixmap(QPixmap(":png/tag11.png"));
        info->setPixmap(QPixmap(":png/tag21.png"));
        npc->setPixmap(QPixmap(":png/tag30.png"));
        scene->setPixmap(QPixmap(":png/tag41.png"));
        widget->setCurrentIndex(2);
        resizeEvent(nullptr);
    }
    else if(p==scene&&st!=Scene)
    {
        st=Scene;
        file->setPixmap(QPixmap(":png/tag11.png"));
        info->setPixmap(QPixmap(":png/tag21.png"));
        npc->setPixmap(QPixmap(":png/tag31.png"));
        scene->setPixmap(QPixmap(":png/tag40.png"));
        widget->setCurrentIndex(3);
        resizeEvent(nullptr);
    }
}

void EditArea::openFile()
{
    QFileDialog fileDialog;
    QStringList fileName;
    fileDialog.setWindowTitle(tr("选择文件"));
    fileDialog.setDirectory(".");
    fileDialog.setNameFilter("*.ptj");
    fileDialog.setFileMode(QFileDialog::ExistingFiles);
    fileDialog.setViewMode(QFileDialog::Detail);
    if(fileDialog.exec())
    {
        fileName = fileDialog.selectedFiles();
    }
}

void EditArea::newFile()
{

}

void EditArea::summary()
{
    widget->setCurrentIndex(SUMMARYWIDGET);
}

void EditArea::announcement()
{
    widget->setCurrentIndex(ANNOUNCEMENTWIDGET);
}

void EditArea::map()
{
    widget->setCurrentIndex(MAPEDITOR);
}

void EditArea::normalNpc()
{
    widget->setCurrentIndex(NORMALNPCEDITOR);
}

void EditArea::keyNpc()
{
    widget->setCurrentIndex(KEYNPCEDITOR);
}

void EditArea::normalScene()
{
    widget->setCurrentIndex(NORMALSCENEEDITOR);
}

void EditArea::battleScene()
{
    widget->setCurrentIndex(BATTLESCENEEDITOR);
}
