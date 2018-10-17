#include "infowidget.h"

namespace ptzs {

InfoWidget::InfoWidget(QWidget *parent) : QWidget(parent)
{
    layout=new QHBoxLayout(this);
    summary=new ClickableLabel(this);
    announcement=new ClickableLabel(this);
    map=new ClickableLabel(this);
    layout->addWidget(summary);
    layout->addWidget(announcement);
    layout->addWidget(map);
    summary->setPixmap(QPixmap(":png/img/summary.png"));
    announcement->setPixmap(QPixmap(":png/img/announcement.png"));
    map->setPixmap(QPixmap(":png/img/map.png"));
}

} // namespace ptzs
