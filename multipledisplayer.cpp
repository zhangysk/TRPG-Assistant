#include "multipledisplayer.h"

namespace ptzs {

MultipleDisplayer::MultipleDisplayer(QWidget *parent) : QWidget(parent)
{
    layout=new QGridLayout(this);
    left=new ClickableLabel(this);
    right=new ClickableLabel(this);
    widgets=new QStackedWidget(this);
    widgets->addWidget(new ClickableLabel);
    ((ClickableLabel*)(widgets->widget(0)))->setPixmap(QPixmap(":/png/add.png"));
    right->setPixmap(QPixmap(":/png/next.png"));
    left->setPixmap(QPixmap(":/png/last.png"));
    right->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);
    left->setMaximumWidth(50);
    right->setMaximumWidth(50);
    widgets->setSizePolicy(QSizePolicy::MinimumExpanding,QSizePolicy::MinimumExpanding);
    layout->addWidget(left,0,0,Qt::AlignCenter);
    layout->addWidget(widgets,0,1);
    layout->addWidget(right,0,2);
    connect(left,SIGNAL(clicked(ClickableLabel*)),this,SLOT(showLast()));
    connect(right,SIGNAL(clicked(ClickableLabel*)),this,SLOT(showNext()));
    connect((ClickableLabel*)(widgets->widget(0)),SIGNAL(clicked(ClickableLabel*)),this,SLOT(addWidget()));
}

MultipleDisplayer::MultipleDisplayer(type t,QWidget *parent) : QWidget(parent)
{
    T=t;
    layout=new QGridLayout(this);
    left=new ClickableLabel(this);
    right=new ClickableLabel(this);
    widgets=new QStackedWidget(this);
    widgets->addWidget(new ClickableLabel);
    ((ClickableLabel*)(widgets->widget(0)))->setPixmap(QPixmap(":/png/add.png"));
    right->setPixmap(QPixmap(":/png/next.png"));
    left->setPixmap(QPixmap(":/png/last.png"));
    right->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Maximum);
    left->setMaximumWidth(50);
    right->setMaximumWidth(50);
    widgets->setSizePolicy(QSizePolicy::MinimumExpanding,QSizePolicy::MinimumExpanding);
    layout->addWidget(left,0,0,Qt::AlignCenter);
    layout->addWidget(widgets,0,1);
    layout->addWidget(right,0,2);
    connect(left,SIGNAL(clicked(ClickableLabel*)),this,SLOT(showLast()));
    connect(right,SIGNAL(clicked(ClickableLabel*)),this,SLOT(showNext()));
    connect((ClickableLabel*)(widgets->widget(0)),SIGNAL(clicked(ClickableLabel*)),this,SLOT(addWidget()));
}

void MultipleDisplayer::showLast()
{
    widgets->setCurrentIndex((widgets->currentIndex()-1+widgets->count())%widgets->count());
}

void MultipleDisplayer::showNext()
{
    widgets->setCurrentIndex((widgets->currentIndex()+1)%widgets->count());
}

void MultipleDisplayer::addWidget()
{
    switch (T) {
    case map:
        widgets->insertWidget(widgets->count()-1,new MapEditor);
        script.addMap();
        ((MapEditor*)(widgets->widget(widgets->count()-1)))->setMap(script.getMap(script.mapNum()-1));
        break;
    case keyNpc:
        widgets->insertWidget(widgets->count()-1,new KeyNpcEditor);
        script.addKeyNPC();
        ((KeyNpcEditor*)(widgets->widget(widgets->count()-1)))->setNpc(script.getKeyNPC(script.keyNpcNum()-1));
        break;
    case normalNpc:
        widgets->insertWidget(widgets->count()-1,new NormalNpcEditor);
        script.addNormalNPC();
        ((NormalNpcEditor*)(widgets->widget(widgets->count()-1)))->setNpc(script.getNormalNPC(script.normalNpcNum()-1));
        break;
    case battleScene:
        widgets->insertWidget(widgets->count()-1,new BattleSceneEditor);
        script.addBattleScene();
        ((BattleSceneEditor*)(widgets->widget(widgets->count()-1)))->setScene(script.getBattleScene(script.battleSceneNum()-1));
        break;
    case normalScene:
        widgets->insertWidget(widgets->count()-1,new NormalSceneEditor);
        script.addNormalScene();
        ((NormalSceneEditor*)(widgets->widget(widgets->count()-1)))->setScene(script.getNormalScene(script.normalSceneNum()-1));
        break;
    default:
        widgets->insertWidget(widgets->count()-1,new QWidget);
        break;
    }
    widgets->setCurrentIndex(widgets->count()-2);
}

} // namespace ptzs
