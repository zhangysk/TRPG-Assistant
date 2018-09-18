#include "keynpceditor.h"

namespace ptzs {

KeyNpcEditor::KeyNpcEditor(QWidget *parent) : QWidget(parent)
{
    scrollArea=new QScrollArea(this);
    widget=new QWidget(this);
    layout=new QGridLayout(scrollArea);
    _layout=new QGridLayout(widget);
    layout->addWidget(widget);
}

} // namespace ptzs
