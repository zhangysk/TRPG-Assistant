#include "infoeditor.h"

namespace ptzs {

InfoEditor::InfoEditor(QWidget *parent) : QWidget(parent)
{
    layout=new QGridLayout(this);
    le1=new QLineEdit("剧本概要：",this);
    le2=new QLineEdit("公告信息：",this);
    le3=new QLineEdit("地图：",this);
    le4=new QLineEdit(this);
    te1=new QTextEdit(this);
    te2=new QTextEdit(this);
    button=new QPushButton("浏览...",this);
    le1->setMaximumWidth(100);
    le2->setMaximumWidth(100);
    le3->setMaximumWidth(100);
    button->setMaximumWidth(100);
    le1->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Minimum);
    le2->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Minimum);
    le3->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Minimum);
    button->setSizePolicy(QSizePolicy::Maximum,QSizePolicy::Minimum);
    le1->setReadOnly(true);
    le1->setFrame(false);
    le2->setReadOnly(true);
    le2->setFrame(false);
    le3->setReadOnly(true);
    le3->setFrame(false);
    layout->addWidget(le1,1,1,Qt::AlignTop);
    layout->addWidget(le2,2,1,Qt::AlignTop);
    layout->addWidget(le3,3,1);
    layout->addWidget(te1,1,2,1,2);
    layout->addWidget(te2,2,2,1,2);
    layout->addWidget(le4,3,2);
    layout->addWidget(button,3,3);
}

} // namespace ptzs
