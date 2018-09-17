#include "announcementeditor.h"

namespace ptzs {

AnnouncementEditor::AnnouncementEditor(QWidget *parent) : QWidget(parent)
{
    layout=new QGridLayout(this);
    layout->setMargin(0);
    te=new QTextEdit(this);
    te->setFont(myFont);
    te->setStyleSheet("background-color:transparent;");
    layout->addWidget(te,0,0);
}

} // namespace ptzs
