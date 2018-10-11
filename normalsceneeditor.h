#ifndef NORMALSCENEEDITOR_H
#define NORMALSCENEEDITOR_H

#include <QScrollArea>
#include <QGridLayout>
#include <QList>
#include <QLineEdit>
#include <QTextEdit>
#include <QMediaPlayer>
#include <QFileDialog>
#include <QDebug>
#include "clickablelabel.h"
#include "normalscene.h"

namespace ptzs {

class NormalSceneEditor : public QScrollArea
{
    Q_OBJECT
public:
    explicit NormalSceneEditor(NormalScene *s,QWidget *parent = nullptr);
    void setScene(NormalScene *s){scene=s;}

private:
    NormalScene *scene;
    QWidget *widget;
    QList<ClickableLabel*> scenePics;
    QList<QTextEdit*> picInfos;
    ClickableLabel *addPic;
    QList<QLineEdit*> bgmFiles;
    QList<ClickableLabel*> playBgm;
    QList<ClickableLabel*> selectBgmFiles;
    QList<QLineEdit*> bgmInfo;
    ClickableLabel *addBgm;
    QGridLayout *layout,*_layout;

signals:

public slots:
    void addPicFile();
    void addBgmFile();
    void setPicFile(ClickableLabel* p);
    void setPicInfo();
    void setBgmFile(ClickableLabel *p);
    void setBgmInfo(QString s);
    void play(ClickableLabel *p);

};

} // namespace ptzs

#endif // NORMALSCENEEDITOR_H
