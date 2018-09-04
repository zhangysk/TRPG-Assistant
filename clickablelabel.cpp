#include "clickablelabel.h"

namespace ptzs {

void ClickableLabel::mousePressEvent(QMouseEvent *e)
{
    if(e->button()==Qt::RightButton)
        emit clicked();
}

} // namespace ptzs
