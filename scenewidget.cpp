#include "scenewidget.h"

namespace ptzs {

SceneWidget::SceneWidget(QWidget *parent) : QWidget(parent)
{
    layout=new QHBoxLayout(this);
    normalScene=new ClickableLabel(this);
    battleScene=new ClickableLabel(this);
    layout->addWidget(normalScene);
    layout->addWidget(battleScene);
    normalScene->setPixmap(QPixmap(":png/normalnpc.png"));
    battleScene->setPixmap(QPixmap(":png/keynpc.png"));
}

} // namespace ptzs
