#include "script.h"
#if _MSC_VER >= 1600
#pragma execution_character_set("utf_8")
#endif
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QString>
#include <QMessageBox>
#include <QTextStream>

namespace ptzs {

Script::Script()
{
}

void Script::fileSaver(QString path){
    //path是最外层的原始路径
    //第一步：在该路径下创建一个文件夹并将其命名为name
    QDir dir;
    QString folder = path + "/";
    folder += this->getName();
    if(!dir.exist(folder)){
        dir.mkpath(folder);
    }
    //在该文件夹下先创建summary，announcement
    //summary
    QString fileSumPath = folder + "/summary.txt";
    QFile fileSummary(fileSumPath);
    if(!fileSummary.open(QIODevice::WriteOnly | QIODevice::Text)){
        QMessageBox::warning(this,tr("错误"),tr("打开文件失败"));
        return;
    }
    else{
        QTextStream textStream(&file);
        textStream << summary;
        fileSummary.close();
    }
    //announcement
    QString fileAnnouncePath = folder + "/announcement.txt";
    QFile fileAnnouncement(fileAnnouncePath);
    if(!fileAnnouncement.open(QIODevice::WriteOnly | QIODevice::Text)){
        QMessageBox::warning(this,tr("错误"),tr("打开文件失败"));
        return;
    }
    else{
        QTextStream textStream(&file);
        textStream << announcement;
        fileAnnouncement.close();
    }

    //创建map文件夹，存储map的一系列图片
    QString mapFolder = folder + "/map";
    if(!dir.exist(mapFolder)){
        dir.mkpath(mapFolder);
    }
    //在map文件夹下存储一系列的图片

}

void Script::onAcSaveTriggered(){

}

} // namespace ptzs
