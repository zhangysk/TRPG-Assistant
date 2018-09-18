#include "normalnpceditor.h"

namespace ptzs {

NormalNpcEditor::NormalNpcEditor(QWidget *parent) : QWidget(parent)
{
    setStyleSheet("background-color:transparent;");
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

    name->setReadOnly(true);
    sex->setReadOnly(true);
    age->setReadOnly(true);
    info->setReadOnly(true);
    avatar->setReadOnly(true);
    name->setAlignment(Qt::AlignRight);
    sex->setAlignment(Qt::AlignRight);
    age->setAlignment(Qt::AlignRight);
    info->setAlignment(Qt::AlignRight);
    avatar->setAlignment(Qt::AlignCenter);
    info->setAlignment(Qt::AlignTop);
    info->setAlignment(Qt::AlignRight);
    _sex->addItem("男");
    _sex->addItem("女");
    connect(_avatar,SIGNAL(clicked(ClickableLabel*)),this,SLOT(selectAvatarFile()));

    layout->addWidget(name,0,0);
    layout->addWidget(_name,0,1);
    layout->addWidget(sex,1,0);
    layout->addWidget(_sex,1,1);
    layout->addWidget(age,2,0);
    layout->addWidget(_age,2,1);
    layout->addWidget(info,3,0);
    layout->addWidget(_info,3,1,1,2);
    layout->addWidget(avatar,0,2);
    layout->addWidget(_avatar,1,2,2,1);
    layout->setColumnStretch(2,1);
    layout->setRowStretch(1,1);
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
        pixmap=QPixmap(fileName.first());
        _avatar->setPixmap(pixmap.scaled(_avatar->size(),Qt::KeepAspectRatio));
        npc.setAvatar(fileName.first());
    }
}

} // namespace ptzs
