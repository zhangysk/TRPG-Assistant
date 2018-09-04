#include "mapeditor.h"

namespace ptzs {

MapEditor::MapEditor(QWidget *parent) : QWidget(parent)
{
    le=new QLineEdit(QString("输入名称"));
    le->setAlignment(Qt::AlignHCenter);
    te=new QTextEdit("地图信息");
    te->setSizePolicy(QSizePolicy::Minimum,QSizePolicy::Maximum);
    label=new ClickableLabel;
    label->setMinimumSize(200,200);
    pixmap.load(":/map.png");
    imgToShow=pixmap.scaled(size(),Qt::KeepAspectRatio);
    label->setPixmap(imgToShow);
    label->setAlignment(Qt::AlignCenter);
    layout=new QVBoxLayout(this);
    button=new QPushButton("提交更改",this);
    layout->addWidget(le);
    layout->addWidget(label,Qt::AlignCenter);
    layout->addWidget(te);
    layout->addWidget(button,0,Qt::AlignRight);
    connect(label,SIGNAL(clicked()),this,SLOT(selectMapFile()));
}

void MapEditor::selectMap(Map *map)
{
    le->setText(map->getName());
    setPixmap(QPixmap(map->getPicFile()));
    te->setText(map->getIntroduction());
}

void MapEditor::resizeEvent(QResizeEvent*)
{
    imgToShow=pixmap.scaled(label->size(),Qt::KeepAspectRatio);
    label->setPixmap(imgToShow);
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
        pixmap.load(fileName.first());
        imgToShow=pixmap.scaled(label->size(),Qt::KeepAspectRatio);
        label->setPixmap(imgToShow);
        return true;
    }
    else
        return false;
}

void MapEditor::setPixmap(const QPixmap &pic)
{
    pixmap=pic;
    imgToShow=pixmap.scaled(label->size(),Qt::KeepAspectRatio);
    label->setPixmap(imgToShow);
}

} // namespace ptzs
