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
        script.addMap();
        widgets->insertWidget(widgets->count()-1,new MapEditor(script.getMap(script.mapNum()-1),this));
        break;
    case keyNpc:
        script.addKeyNPC();
        widgets->insertWidget(widgets->count()-1,new KeyNpcEditor(script.getKeyNPC(script.keyNpcNum()-1),this));
        break;
    case normalNpc:
        script.addNormalNPC();
        widgets->insertWidget(widgets->count()-1,new NormalNpcEditor(script.getNormalNPC(script.normalNpcNum()-1),this));
        break;
    case battleScene:
        script.addBattleScene();
        widgets->insertWidget(widgets->count()-1,new BattleSceneEditor(script.getBattleScene(script.battleSceneNum()-1),this));
        break;
    case normalScene:
        script.addNormalScene();
        widgets->insertWidget(widgets->count()-1,new NormalSceneEditor(script.getNormalScene(script.normalSceneNum()-1),this));
        break;
    default:
        widgets->insertWidget(widgets->count()-1,new QWidget);
        break;
    }
    widgets->setCurrentIndex(widgets->count()-2);
}

} // namespace ptzs
