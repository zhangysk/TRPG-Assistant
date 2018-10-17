#include "filewidget.h"

namespace ptzs {

FileWidget::FileWidget(QWidget *parent) : QWidget(parent)
{
    layout=new QHBoxLayout(this);
    open=new ClickableLabel(this);
    _new=new ClickableLabel(this);
    open->setPixmap(QPixmap(":png/img/openfile.png"));
    _new->setPixmap(QPixmap(":png/img/newfile.png"));
    layout->addWidget(open);
    layout->addWidget(_new);
}

} // namespace ptzs
