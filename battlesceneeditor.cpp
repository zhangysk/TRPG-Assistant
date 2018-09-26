#include "battlesceneeditor.h"

namespace ptzs {

BattleSceneEditor::BattleSceneEditor(QWidget *parent) : QScrollArea(parent)
{
    scene=new BattleScene;
    widget=new QWidget(this);
    addPic=new ClickableLabel(this);
    addBgm=new ClickableLabel(this);
    _layout=new QGridLayout(this);
    layout=new QGridLayout(widget);
    addPic->setPixmap(QPixmap(":/png/addpicfile.png"));
    addBgm->setPixmap(QPixmap(":/png/addbgmfile.png"));

    _layout->addWidget(widget);
    layout->addWidget(addPic,0,0);
    layout->addWidget(addBgm,1,0);
    connect(addPic,SIGNAL(clicked(ClickableLabel*)),this,SLOT(addPicFile()));
    connect(addBgm,SIGNAL(clicked(ClickableLabel*)),this,SLOT(addBgmFile()));
}

void BattleSceneEditor::addPicFile()
{
    delete layout;
    layout=new QGridLayout(widget);
    layout->setColumnStretch(0,5);
    layout->setColumnStretch(1,1);
    layout->setColumnStretch(2,4);
    scenePics.append(new ClickableLabel);
    picInfos.append(new QTextEdit);
    for(int i=0;i<scenePics.count();i++)
    {
        layout->addWidget(scenePics.at(i),i,0);
        layout->addWidget(picInfos.at(i),i,1,1,2);
    }
    layout->addWidget(addPic,scenePics.count(),0,1,3);
    for(int i=0;i<bgmFiles.count();i++)
    {
        layout->addWidget(bgmFiles.at(i),scenePics.count()+1+i,0);
        layout->addWidget(playBgm.at(i),scenePics.count()+1+i,1);
        layout->addWidget(selectBgmFiles.at(i),scenePics.count()+1+i,2);
    }
    layout->addWidget(addBgm,scenePics.count()+bgmFiles.count()+1,0,1,3);
}

void BattleSceneEditor::addBgmFile()
{
    delete layout;
    layout=new QGridLayout(widget);
    layout->setColumnStretch(0,5);
    layout->setColumnStretch(1,1);
    layout->setColumnStretch(2,4);
    bgmFiles.append(new QLineEdit);
    playBgm.append(new ClickableLabel);
    selectBgmFiles.append(new ClickableLabel);
    for(int i=0;i<scenePics.count();i++)
    {
        layout->addWidget(scenePics.at(i),i,0);
        layout->addWidget(picInfos.at(i),i,1,1,2);
    }
    layout->addWidget(addPic,scenePics.count(),0,1,3);
    for(int i=0;i<bgmFiles.count();i++)
    {
        layout->addWidget(bgmFiles.at(i),scenePics.count()+1+i,0);
        layout->addWidget(playBgm.at(i),scenePics.count()+1+i,1);
        layout->addWidget(selectBgmFiles.at(i),scenePics.count()+1+i,2);
    }
    layout->addWidget(addBgm,scenePics.count()+bgmFiles.count()+1,0,1,3);
}

} // namespace ptzs
