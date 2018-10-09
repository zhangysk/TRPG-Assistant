#include "normalnpceditor.h"

namespace ptzs {

NormalNpcEditor::NormalNpcEditor(QWidget *parent) : QScrollArea(parent)
{
    setStyleSheet("background-color:transparent;");

    widget=new QWidget(this);
    name=new QLineEdit("姓名：",this);
    _name=new QLineEdit(this);
    sex=new QLineEdit("性别：",this);
    _sex=new QComboBox(this);
    age=new QLineEdit("年龄：",this);
    _age=new QLineEdit(this);
    info=new QLineEdit("人物信息：",this);
    _info=new QTextEdit(this);
    avatar=new QLineEdit("头像",this);
    _avatar=new ClickableLabel(this);
    layout=new QGridLayout(this);
    _layout=new QGridLayout(this);

    widget->setSizePolicy(QSizePolicy::MinimumExpanding,QSizePolicy::MinimumExpanding);
    name->setReadOnly(true);
    sex->setReadOnly(true);
    age->setReadOnly(true);
    info->setReadOnly(true);
    avatar->setReadOnly(true);
    name->setAlignment(Qt::AlignRight);
    sex->setAlignment(Qt::AlignRight);
    age->setAlignment(Qt::AlignRight);
    info->setAlignment(Qt::AlignRight);
    info->setAlignment(Qt::AlignRight);
    _info->setSizePolicy(QSizePolicy::MinimumExpanding,QSizePolicy::Maximum);
    _info->setMaximumHeight(100);
    avatar->setAlignment(Qt::AlignCenter);
    connect(_avatar,SIGNAL(clicked(ClickableLabel*)),this,SLOT(selectAvatarFile()));
    _sex->addItem("男");
    _sex->addItem("女");
    layout->addWidget(widget);
    _layout->addWidget(name,0,0);
    _layout->addWidget(_name,0,1);
    _layout->addWidget(sex,1,0);
    _layout->addWidget(_sex,1,1);
    _layout->addWidget(age,2,0);
    _layout->addWidget(_age,2,1);
    _layout->addWidget(info,3,0,Qt::AlignTop);
    _layout->addWidget(_info,3,1);
    _layout->addWidget(avatar,4,0,1,2);
    _layout->addWidget(_avatar,5,0,1,2);
    _layout->setColumnStretch(1,1);
    _layout->setRowStretch(5,1);
    widget->setLayout(_layout);
    connect(_name,SIGNAL(textChanged(QString)),this,SLOT(set()));
    connect(_sex,SIGNAL(currentIndexChanged(int)),this,SLOT(set()));
    connect(_age,SIGNAL(textChanged(QString)),this,SLOT(set()));
    connect(_info,SIGNAL(textChanged()),this,SLOT(set()));
}


void NormalNpcEditor::selectAvatarFile()
{
    QFileDialog fileDialog;
    QStringList fileName;
    fileDialog.setWindowTitle(tr("选择文件"));
    fileDialog.setDirectory(".");
    fileDialog.setNameFilter("*.jpg *.jpeg *.png *.bmp *.ico");
    fileDialog.setFileMode(QFileDialog::ExistingFiles);
    fileDialog.setViewMode(QFileDialog::Detail);
    if(fileDialog.exec())
    {
        fileName = fileDialog.selectedFiles();
    }
    if(fileName.size())
    {
        _avatar->setPixmap(QPixmap(fileName.first()));
        npc->setAvatar(fileName.first());
    }
}

void NormalNpcEditor::set()
{
    if(sender()==_name)
        npc->setName(((QLineEdit*)sender())->text());
    else if(sender()==_sex)
        npc->setSex((NormalNpc::esex)(((QComboBox*)sender())->currentIndex()));
    else if(sender()==_age)
        npc->setAge(((QLineEdit*)sender())->text().toInt());
    else if(sender()==_info)
        npc->setGeRenXinXi(((QTextEdit*)sender())->toPlainText());
}

} // namespace ptzs
