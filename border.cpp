#include "border.h"

namespace ptzs {

Border::Border(QWidget *parent) : QWidget(parent)
{
    setLoc(top);
}

Border::Border(location l,QWidget *parent) : QWidget(parent)
{
    setLoc(l);
}

void Border::setLoc(location l)
{
    if(l==top||l==bottom)
    {
        setFixedHeight(4);
        setSizePolicy(QSizePolicy::MinimumExpanding,QSizePolicy::Fixed);
        setCursor(Qt::SizeVerCursor);
    }
    else if(l==left||l==right)
    {
        setFixedWidth(4);
        setSizePolicy(QSizePolicy::Fixed,QSizePolicy::MinimumExpanding);
        setCursor(Qt::SizeHorCursor);
    }
    else if(l==topLeft||l==bottomRight)
    {
        setFixedSize(4,4);
        setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
        setCursor(Qt::SizeFDiagCursor);
    }
    else if(l==bottomLeft||l==topRight)
    {
        setFixedSize(4,4);
        setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
        setCursor(Qt::SizeBDiagCursor);
    }
    loc=l;
}

void Border::mousePressEvent(QMouseEvent *ev)
{
    startPos=ev->globalPos();
}

void Border::mouseMoveEvent(QMouseEvent *ev)
{
    if(loc==top||loc==topLeft||loc==topRight)
    {
        if(((QWidget*)parent())->height()+((QWidget*)parent())->y()-ev->globalY()<((QWidget*)parent())->minimumHeight())
        {
            ((QWidget*)parent())->setGeometry(((QWidget*)parent())->x(),((QWidget*)parent())->y()+((QWidget*)parent())->height()-((QWidget*)parent())->minimumHeight(),((QWidget*)parent())->width(),((QWidget*)parent())->minimumHeight());
        }
        else
        {
            ((QWidget*)parent())->setGeometry(((QWidget*)parent())->x(),ev->globalY(),((QWidget*)parent())->width(),((QWidget*)parent())->height()+((QWidget*)parent())->y()-ev->globalY());
        }
    }
    if(loc==bottom||loc==bottomLeft||loc==bottomRight)
    {
        ((QWidget*)parent())->setGeometry(((QWidget*)parent())->x(),((QWidget*)parent())->y(),((QWidget*)parent())->width(),ev->globalY()-((QWidget*)parent())->y());
    }
    if(loc==left||loc==topLeft||loc==bottomLeft)
    {
        if(((QWidget*)parent())->width()+((QWidget*)parent())->x()-ev->globalX()<((QWidget*)parent())->minimumWidth())
        {
            ((QWidget*)parent())->setGeometry(((QWidget*)parent())->x()+((QWidget*)parent())->width()-((QWidget*)parent())->minimumWidth(),((QWidget*)parent())->y(),((QWidget*)parent())->minimumWidth(),((QWidget*)parent())->height());
        }
        else
        {
            ((QWidget*)parent())->setGeometry(ev->globalX(),((QWidget*)parent())->y(),((QWidget*)parent())->width()+((QWidget*)parent())->x()-ev->globalX(),((QWidget*)parent())->height());
        }
    }
    if(loc==right||loc==topRight||loc==bottomRight)
    {
        ((QWidget*)parent())->setGeometry(((QWidget*)parent())->x(),((QWidget*)parent())->y(),ev->globalX()-((QWidget*)parent())->x(),((QWidget*)parent())->height());
    }
}

} // namespace ptzs
