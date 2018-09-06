#include "clickablelabel.h"

namespace ptzs {

ClickableLabel::ClickableLabel(QWidget *parent) : QLabel(parent)
{
    setCursor(QCursor(Qt::PointingHandCursor));
    change=false;
    scaled=false;
}


void ClickableLabel::mouseReleaseEvent(QMouseEvent *e)
{
    if(e->button()==Qt::LeftButton&&underMouse())
        emit clicked(this);
}

void ClickableLabel::enterEvent(QEvent *e)
{

}

void ClickableLabel::leaveEvent(QEvent *e)
{

}


} // namespace ptzs
