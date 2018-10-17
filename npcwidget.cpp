#include "npcwidget.h"

namespace ptzs {

NpcWidget::NpcWidget(QWidget *parent) : QWidget(parent)
{
    layout=new QHBoxLayout(this);
    normalNpc=new ClickableLabel(this);
    keyNpc=new ClickableLabel(this);
    layout->addWidget(normalNpc);
    layout->addWidget(keyNpc);
    normalNpc->setPixmap(QPixmap(":png/img/normalnpc.png"));
    keyNpc->setPixmap(QPixmap(":png/img/keynpc.png"));
}

} // namespace ptzs
