#include "scenepicshower.h"

namespace ptzs {

ScenePicShower::ScenePicShower(QWidget *parent) : QWidget(parent)
{
    layout=new QGridLayout(this);
    name=new QLineEdit(tr("name:"),this);
    name->setReadOnly(true);
    layout->addWidget(name,0,0);
    nameEditor=new QLineEdit(this);
    layout->addWidget(nameEditor,0,1);
    label=new QLabel(this);
    layout->addWidget(label,1,0,1,2);
    info=new QLineEdit(tr("info"),this);
    info->setReadOnly(true);
    layout->addWidget(info,2,0);
    infoEditor=new QTextEdit(this);
    layout->addWidget(infoEditor,2,1);
}

} // namespace ptzs
