#include "battlesceneeditor.h"

namespace ptzs {

BattleSceneEditor::BattleSceneEditor(BattleScene *s,QWidget *parent) : QScrollArea(parent)
{
    scene=s;
    widget=new QWidget(this);
    addPic=new ClickableLabel(this);
    addBgm=new ClickableLabel(this);
    _layout=new QGridLayout(this);
    layout=new QGridLayout(widget);

    setWidget(widget);
    widget->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::MinimumExpanding);
    addPic->setMinimumHeight(200);
    addBgm->setMinimumHeight(20);
    addBgm->setMaximumHeight(20);
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
    scenePics.last()->setPixmap(QPixmap(":/png/openfile.png"));
    scenePics.last()->setMinimumHeight(200);
    picInfos.append(new QTextEdit);
    connect(scenePics.last(),SIGNAL(clicked(ClickableLabel*)),this,SLOT(setPicFile(ClickableLabel*)));
    connect(picInfos.last(),SIGNAL(textChanged()),this,SLOT(setPicInfo()));
    for(int i=0;i<scenePics.count();i++)
    {
        layout->addWidget(scenePics.at(i),i,0);
        layout->addWidget(picInfos.at(i),i,1,1,3);
    }
    layout->addWidget(addPic,scenePics.count(),0,1,4);
    for(int i=0;i<bgmFiles.count();i++)
    {
        layout->addWidget(bgmFiles.at(i),scenePics.count()+1+i,0);
        layout->addWidget(playBgm.at(i),scenePics.count()+1+i,1);
        layout->addWidget(selectBgmFiles.at(i),scenePics.count()+1+i,2);
        layout->addWidget(bgmInfo.at(i),scenePics.count()+1+i,3);
    }
    layout->addWidget(addBgm,scenePics.count()+bgmFiles.count()+1,0,1,4);
    widget->setMinimumHeight(210*scenePics.count()+bgmFiles.count()*25+240);
    scene->addPic();
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
    bgmInfo.append(new QLineEdit);
    bgmFiles.last()->setMinimumHeight(20);
    connect(playBgm.last(),SIGNAL(clicked(ClickableLabel*)),this,SLOT(play(ClickableLabel*)));
    connect(selectBgmFiles.last(),SIGNAL(clicked(ClickableLabel*)),this,SLOT(setBgmFile(ClickableLabel*)));
    connect(bgmInfo.last(),SIGNAL(textChanged(QString)),this,SLOT(setBgmInfo(QString)));
    for(int i=0;i<scenePics.count();i++)
    {
        layout->addWidget(scenePics.at(i),i,0);
        layout->addWidget(picInfos.at(i),i,1,1,3);
    }
    layout->addWidget(addPic,scenePics.count(),0,1,4);
    for(int i=0;i<bgmFiles.count();i++)
    {
        layout->addWidget(bgmFiles.at(i),scenePics.count()+1+i,0);
        layout->addWidget(playBgm.at(i),scenePics.count()+1+i,1);
        layout->addWidget(selectBgmFiles.at(i),scenePics.count()+1+i,2);
        layout->addWidget(bgmInfo.at(i),scenePics.count()+1+i,3);
    }
    layout->addWidget(addBgm,scenePics.count()+bgmFiles.count()+1,0,1,4);
    widget->setMinimumHeight(210*scenePics.count()+bgmFiles.count()*25+240);
    scene->addMusic();
}

void BattleSceneEditor::setPicFile(ClickableLabel* p)
{
    QFileDialog fileDialog;
    QStringList fileName;
    fileDialog.setWindowTitle(tr("选择文件"));
    fileDialog.setDirectory(".");
    fileDialog.setNameFilter("*.jpg *.jpeg *.png *.bmp *.ico");
    fileDialog.setFileMode(QFileDialog::ExistingFiles);
    fileDialog.setViewMode(QFileDialog::Detail);
    if(fileDialog.exec())
    {
        fileName = fileDialog.selectedFiles();
    }
    if(fileName.size())
    {
        p->setPixmap(QPixmap(fileName.first()).scaled(p->size(),Qt::KeepAspectRatio));
        scene->setPic(scenePics.indexOf(p),fileName.first());
    }
}

void BattleSceneEditor::play(ClickableLabel *p)
{
    static QMediaPlayer *player=new QMediaPlayer(this);
    player->setMedia(QMediaContent(QUrl::fromLocalFile(bgmFiles.at(playBgm.indexOf(p))->text())));
    {
        player->play();
    }
}

void BattleSceneEditor::setBgmFile(ClickableLabel *p)
{
    QFileDialog fileDialog;
    QStringList fileName;
    fileDialog.setWindowTitle(tr("选择文件"));
    fileDialog.setDirectory(".");
    fileDialog.setFileMode(QFileDialog::ExistingFiles);
    fileDialog.setViewMode(QFileDialog::Detail);
    if(fileDialog.exec())
    {
        fileName = fileDialog.selectedFiles();
    }
    if(fileName.size())
    {
        bgmFiles.at(selectBgmFiles.indexOf(p))->setText(fileName.first());
        scene->setMusic(selectBgmFiles.indexOf(p),fileName.first());
    }
}

void BattleSceneEditor::setPicInfo()
{
    scene->setPicInfo(picInfos.indexOf((QTextEdit*)sender()),((QTextEdit*)sender())->toPlainText());
}

void BattleSceneEditor::setBgmInfo(QString s)
{
    scene->setMusicInfo(bgmInfo.indexOf((QLineEdit*)sender()),s);
}

} // namespace ptzs
