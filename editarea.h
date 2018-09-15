#ifndef EDITAREA_H
#define EDITAREA_H

#include <QFrame>
#include <QStackedWidget>
#include <QFileDialog>
#include "clickablelabel.h"
#include "filewidget.h"
#include "infowidget.h"
#include "npcwidget.h"
#include "scenewidget.h"
#include "summaryeditor.h"
#include "announcementeditor.h"
#include "multipledisplayer.h"

namespace ptzs {
    class EditArea : public QFrame
    {
        Q_OBJECT
    public:
        explicit EditArea(QWidget *parent = nullptr);
        enum state
        {
            File,
            Info,
            Npc,
            Scene,
        };
        enum widgetType
        {
            FILEWIDGET,
            INFOWIDGET,
            NPCWIDGET,
            SCENEWIDGET,
            SUMMARYWIDGET,
            ANNOUNCEMENTWIDGET,
            MAPEDITOR,
            NORMALNPCEDITOR,
            KEYNPCEDITOR,
            NORMALSCENEEDITOR,
            BATTLESCENEEDITOR,
        };

    private:
        ClickableLabel *file,*info,*npc,*scene;
        ClickableLabel *background;
        QLabel *frame;
        state st;
        QStackedWidget *widget;

    protected:
        void resizeEvent(QResizeEvent *ev);

    signals:

    public slots:
        void changeState(ClickableLabel *p);
        void openFile();
        void newFile();
        void summary();
        void announcement();
        void map();
        void normalNpc();
        void keyNpc();
        void normalScene();
        void battleScene();

    };

}

#endif // EDITAREA_H
