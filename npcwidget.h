#ifndef NPCWIDGET_H
#define NPCWIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include "clickablelabel.h"

namespace ptzs {

class NpcWidget : public QWidget
{
    Q_OBJECT
public:
    explicit NpcWidget(QWidget *parent = nullptr);
    ClickableLabel* normalNpcLabel(){return normalNpc;}
    ClickableLabel* keyNpcLabel(){return keyNpc;}

private:
    QHBoxLayout *layout;
    ClickableLabel *normalNpc,*keyNpc;

signals:

public slots:
};

} // namespace ptzs

#endif // NPCWIDGET_H
