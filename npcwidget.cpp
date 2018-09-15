#include "npcwidget.h"

namespace ptzs {

NpcWidget::NpcWidget(QWidget *parent) : QWidget(parent)
{
    layout=new QHBoxLayout(this);
    normalNpc=new ClickableLabel(this);
    keyNpc=new ClickableLabel(this);
    layout->addWidget(normalNpc);
    layout->addWidget(keyNpc);
    normalNpc->setPixmap(QPixmap(":png/normalnpc.png"));
    keyNpc->setPixmap(QPixmap(":png/keynpc.png"));
}

} // namespace ptzs
