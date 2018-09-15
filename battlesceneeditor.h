#ifndef BATTLESCENEEDITOR_H
#define BATTLESCENEEDITOR_H

#include <QScrollArea>
#include <QGridLayout>
#include <QList>
#include <QTableWidget>
#include <QLabel>
#include <QPushButton>
#include <QHeaderView>
#include "battlescene.h"
#include "scenepicshower.h"

namespace ptzs {

class BattleSceneEditor : public QScrollArea
{
    Q_OBJECT
public:
    explicit BattleSceneEditor(QWidget *parent = nullptr);
    BattleSceneEditor(BattleScene *scene);

private:
    BattleScene *scene;
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

#endif // BATTLESCENEEDITOR_H
