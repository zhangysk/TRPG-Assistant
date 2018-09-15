#ifndef SCENEWIDGET_H
#define SCENEWIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include "clickablelabel.h"

namespace ptzs {

class SceneWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SceneWidget(QWidget *parent = nullptr);
    ClickableLabel* normalSceneLabel(){return normalScene;}
    ClickableLabel* battleSceneLabel(){return battleScene;}

private:
    QHBoxLayout *layout;
    ClickableLabel *normalScene,*battleScene;

signals:

public slots:
};

} // namespace ptzs

#endif // SCENEWIDGET_H
