#include "mapeditor.h"

namespace ptzs {

MapEditor::MapEditor(QWidget *parent) : QWidget(parent)
{
    map=nullptr;
    le=new QLineEdit(QString("输入名称"));
    le->setAlignment(Qt::AlignHCenter);
    te=new QTextEdit("地图信息");
    te->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Maximum);
    label=new ClickableLabel;
    label->setMinimumSize(200,200);
    pixmap.load(":/map.png");
    label->setPixmap(pixmap.scaled(label->size(),Qt::KeepAspectRatio));
    label->setAlignment(Qt::AlignCenter);
    layout=new QVBoxLayout(this);
    layout->addWidget(le);
    layout->addWidget(label,Qt::AlignCenter);
    layout->addWidget(te);
    connect(label,SIGNAL(clicked()),this,SLOT(selectMapFile()));
    connect(le,SIGNAL(editingFinished()),this,SLOT(setMapName()));
    connect(te,SIGNAL(textChanged()),this,SLOT(setMapInfo()));
}

void MapEditor::selectMap(Map *m,int i)
{
    map=m;
    le->setText(map->getName());
    setPixmap(QPixmap(map->getPicFile()));
    te->setText(map->getIntroduction());
}

void MapEditor::setPixmap(const QPixmap &pic)
{
    pixmap=pic;
    label->setPixmap(pixmap.scaled(label->size(),Qt::KeepAspectRatio));
}

void MapEditor::resizeEvent(QResizeEvent*)
{
    label->setPixmap(pixmap.scaled(label->size(),Qt::KeepAspectRatio));
}

bool MapEditor::selectMapFile()
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
        setPixmap(QPixmap(fileName.first()));
        map->setPicFile(fileName.first());
        return true;
    }
    else
        return false;
}

void MapEditor::setMapName()
{
    map->setName(le->text());
}

void MapEditor::setMapInfo()
{
    map->setIntroduction(te->toPlainText());
}

} // namespace ptzs
