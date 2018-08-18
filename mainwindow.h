#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "tabwidget.h"

namespace ptzs{
    class MainWindow : public QMainWindow
    {
        Q_OBJECT
    public:
        explicit MainWindow(QWidget *parent = nullptr);

    private:
        TabWidget* tabWidget;

    signals:

    public slots:
    };
}

#endif // MAINWINDOW_H
