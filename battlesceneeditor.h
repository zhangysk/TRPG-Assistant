#ifndef BATTLESCENEEDITOR_H
#define BATTLESCENEEDITOR_H

#include <QScrollArea>
#include <QGridLayout>
#include <QList>
#include <QLineEdit>
#include <QTextEdit>
#include "clickablelabel.h"
#include "battlescene.h"

namespace ptzs {

class BattleSceneEditor : public QScrollArea
{
    Q_OBJECT
public:
    explicit BattleSceneEditor(QWidget *parent = nullptr);

private:
    BattleScene *scene;
    QWidget *widget;
    QList<ClickableLabel*> scenePics;
    QList<QTextEdit*> picInfos;
    ClickableLabel *addPic;
    QList<QLineEdit*> bgmFiles;
    QList<ClickableLabel*> playBgm;
    QList<ClickableLabel*> selectBgmFiles;
    ClickableLabel *addBgm;
    QGridLayout *layout,*_layout;

signals:

public slots:
    void addPicFile();
    void addBgmFile();

};

} // namespace ptzs

#endif // BATTLESCENEEDITOR_H
