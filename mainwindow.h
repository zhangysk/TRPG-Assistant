#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QPainter>
#include "clickablelabel.h"
#include "editarea.h"

namespace ptzs{
    class MainWindow : public QWidget
    {
        Q_OBJECT
    public:
        explicit MainWindow(QWidget *parent = nullptr);

    protected:
        void resizeEvent(QResizeEvent *ev);
        void paintEvent(QPaintEvent *ev);

    private:
        ClickableLabel *close,*minimize,*maximize;
        EditArea *editArea;
        QGridLayout *layout;

    signals:

    public slots:
        void maximizing();
    };
}

#endif // MAINWINDOW_H
