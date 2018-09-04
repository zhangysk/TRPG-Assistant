#ifndef SCENE_BATTLE_EDITOR_H
#define SCENE_BATTLE_EDITOR_H

#include <QScrollArea>
#include <QList>
#include <QLabel>
#include <QLineEdit>
#include <QGridLayout>
#include <QScrollArea>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QResizeEvent>
#include <QTableWidget>
#include <QHeaderView>
#include "scene_battle.h"
#include "scenepicshower.h"

namespace ptzs {

class scene_battle_editor : public QScrollArea
{
    Q_OBJECT
public:
    explicit scene_battle_editor(QWidget *parent = nullptr);
    scene_battle_editor(scene_battle *scene);

private:
    scene_battle *scene;
    QGridLayout *layout,*lay;
    QList<ScenePicShower*> *picShowers;
    QTableWidget *musicShower;
    QLabel *addPic;
    QPushButton *addMusic;
    QWidget *widget;
    void resizeEvent(QResizeEvent *);
signals:

public slots:
};

} // namespace ptzs

#endif // SCENE_BATTLE_EDITOR_H
