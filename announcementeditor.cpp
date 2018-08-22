#include "announcementeditor.h"

namespace ptzs {

AnnouncementEditor::AnnouncementEditor(QWidget *parent) : QWidget(parent)
{
    layout=new QGridLayout(this);
    layout->setMargin(0);
    te=new QTextEdit(this);
    button=new QPushButton("提交更改",this);
    layout->addWidget(te,1,1);
    layout->addWidget(button,2,1,Qt::AlignRight);
    button->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Minimum);
}

} // namespace ptzs
