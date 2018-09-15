#ifndef MULTIPLEDISPLAYER_H
#define MULTIPLEDISPLAYER_H

#include <QWidget>
#include <QStackedWidget>
#include <QGridLayout>
#include "clickablelabel.h"
#include "mapeditor.h"
#include "keynpceditor.h"
#include "normalnpceditor.h"
#include "battlesceneeditor.h"
#include "normalsceneeditor.h"

namespace ptzs {
class MultipleDisplayer : public QWidget
{
    Q_OBJECT
public:
    enum type
    {
        map,
        keyNpc,
        normalNpc,
        battleScene,
        normalScene,
    };
    explicit MultipleDisplayer(QWidget *parent = nullptr);
    MultipleDisplayer(type t,QWidget *parent = nullptr);

private:
    QStackedWidget *widgets;
    QGridLayout *layout;
    ClickableLabel *left,*right;
    QWidget *centralWidget;
    type T;
    int index;

signals:

public slots:
    void showLast();
    void showNext();
    void addWidget();

};

} // namespace ptzs

#endif // MULTIPLEDISPLAYER_H
