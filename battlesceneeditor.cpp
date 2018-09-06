#include "battlesceneeditor.h"

namespace ptzs {

BattleSceneEditor::BattleSceneEditor(QWidget *parent) : QScrollArea(parent)
{
    setMinimumWidth(250);
    setBackgroundRole(QPalette::Light);
    widget=new QWidget;
    lay=new QGridLayout(this);
    lay->addWidget(widget,1,1);
    widget->setBackgroundRole(QPalette::Dark);
    scene=new BattleScene;
    picShowers=new QList<ScenePicShower*>;

    musicShower=new QTableWidget(1,4,widget);
    musicShower->horizontalHeader()->setStretchLastSection(true);;
    musicShower->setSelectionBehavior(QAbstractItemView::SelectRows);
    QStringList header;
    header<<tr("name")<<tr("file location")<<tr("info")<<tr("play");
    musicShower->setHorizontalHeaderLabels(header);
    musicShower->setFrameShape(QFrame::NoFrame);
    musicShower->verticalHeader()->hide();
    musicShower->horizontalHeader()->resizeSection(3,20);

    addPic=new QLabel(widget);
    addPic->setScaledContents(true);
    addPic->setMinimumSize(200,300);
    addPic->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Minimum);
    addPic->setPixmap(QPixmap(":/map.png"));
    addMusic=new QPushButton(widget);
    layout=new QGridLayout(widget);
    widget->setLayout(layout);
    layout->addWidget(addPic,0,0,Qt::AlignCenter);
    layout->addWidget(musicShower,1,0);
    layout->addWidget(addMusic,2,0);
}

void BattleSceneEditor::resizeEvent(QResizeEvent *e)
{
    int column=width()/200;
    delete layout;
    layout=new QGridLayout;
    for(int i=0;i<scene->picNum();i++)
    {
        layout->addWidget(picShowers->at(i),i/column,i%column);
    }
    layout->addWidget(addPic,(picShowers->size()+1)/column,(picShowers->size()+1)%column,Qt::AlignCenter);
    layout->addWidget(musicShower,(picShowers->size()+1)/column+1,0,1,column);
    layout->addWidget(addMusic,(picShowers->size()+1)/column+2,0,1,column,Qt::AlignLeft);
    layout->setMargin(2);
    widget->setLayout(layout);
}

} // namespace ptzs
