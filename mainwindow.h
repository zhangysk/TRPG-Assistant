#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFrame>
#include <QGridLayout>
#include <QMouseEvent>
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
        void paintEvent(QPaintEvent *ev);
        void mousePressEvent(QMouseEvent *ev);
        void mouseMoveEvent(QMouseEvent *ev);

    private:
        QPoint startPos;
        ClickableLabel *close,*minimize,*maximize;
        EditArea *editArea;
        QGridLayout *layout;
        QPixmap background;
        Border* border[8];

    signals:

    public slots:
        void maximizing();
    };
}

#endif // MAINWINDOW_H
