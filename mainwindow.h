#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenuBar>
#include <QToolBar>
#include <QDebug>
#include "announcementeditor.h"
#include "editarea.h"
#include "npc.h"
#include "scene.h"
#include "summaryeditor.h"
#include "tabwidget.h"
#include "treewidget.h"

namespace ptzs{
    class MainWindow : public QMainWindow
    {
        Q_OBJECT
    public:
        explicit MainWindow(QWidget *parent = nullptr);

    private:
        TabWidget* tabWidget;
        QMenu* file;
        QMenu* edit;
        QMenu* help;
        QAction* openAction;
        QAction* newAction;
        QAction* saveAction;

    signals:

    public slots:
    };
}

#endif // MAINWINDOW_H
