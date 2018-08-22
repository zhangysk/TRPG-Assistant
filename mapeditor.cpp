#include "mapeditor.h"

namespace ptzs {

MapEditor::MapEditor(QWidget *parent) : QWidget(parent)
{
    map=new Map;
    le=new QLineEdit(QString("输入名称"));
    le->setAlignment(Qt::AlignHCenter);
    te=new QTextEdit("地图信息");
    te->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Maximum);
    label=new QLabel;
    label->setMinimumSize(200,200);
    pixmap=new QPixmap(":/map.png");
    imgToShow=new QPixmap;
    *imgToShow=pixmap->scaled(size(),Qt::KeepAspectRatio);
    label->setPixmap(*pixmap);
    label->setAlignment(Qt::AlignCenter);
    layout=new QVBoxLayout(this);
    button=new QPushButton("提交更改",this);
    layout->addWidget(le);
    layout->addWidget(label,Qt::AlignCenter);
    layout->addWidget(te);
    layout->addWidget(button,0,Qt::AlignRight);
}

void MapEditor::resizeEvent(QResizeEvent *size)
{
    *imgToShow=pixmap->scaled(label->size(),Qt::KeepAspectRatio);
    label->setPixmap(*imgToShow);
}

} // namespace ptzs
