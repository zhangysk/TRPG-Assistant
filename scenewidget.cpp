#include "scenewidget.h"

namespace ptzs {

SceneWidget::SceneWidget(QWidget *parent) : QWidget(parent)
{
    layout=new QHBoxLayout(this);
    normalScene=new ClickableLabel(this);
    battleScene=new ClickableLabel(this);
    layout->addWidget(normalScene);
    layout->addWidget(battleScene);
    normalScene->setPixmap(QPixmap(":png/img/normalnpc.png"));
    battleScene->setPixmap(QPixmap(":png/img/keynpc.png"));
}

} // namespace ptzs
