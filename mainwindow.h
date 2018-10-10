#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFrame>
#include <QGridLayout>
#include <QMouseEvent>
#include <QFontDatabase>
#include <QFont>
#include "data.h"
#include "clickablelabel.h"
#include "editarea.h"
#include "border.h"

namespace ptzs{
    class MainWindow : public QFrame
    {
        Q_OBJECT
    public:
        explicit MainWindow(QWidget *parent = nullptr);

    protected:
        void resizeEvent(QResizeEvent *ev);
        void mousePressEvent(QMouseEvent *ev);
        void mouseMoveEvent(QMouseEvent *ev);

    private:
        QPoint startPos;
        ClickableLabel *close,*minimize,*maximize;
        ClickableLabel *save;
        EditArea *editArea;
        QGridLayout *layout;
        QPixmap background;
        Border* border[8];

    signals:

    public slots:
        void maximizing();
        void _save();
    };
}

#endif // MAINWINDOW_H
