#ifndef EDITAREA_H
#define EDITAREA_H

#include <QWidget>
#include "treewidget.h"
#include "summaryeditor.h"
#include "announcementeditor.h"
#include "mapeditor.h"
#include "keynpceditor.h"
#include "normalnpceditor.h"
#include "battlesceneeditor.h"
#include "normalsceneeditor.h"

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

    private:
        ClickableLabel *file,*info,*npc,*scene;
        ClickableLabel *background;
        state st;
        SummaryEditor *summaryEditor;
        AnnouncementEditor *announcementEditor;
        MapEditor *mapEditor;
        NormalNpcEditor *normalNpcEditor;
        KeyNpcEditor *keyNpcEditor;
        NormalSceneEditor *normalSceneEditor;
        BattleSceneEditor *battleSceneEditor;

    protected:
        void resizeEvent(QResizeEvent *ev);

    signals:

    public slots:
        void changeState(ClickableLabel *p);
    };

}

#endif // EDITAREA_H
