#ifndef EDITAREA_H
#define EDITAREA_H

#include <QSplitter>
#include "treewidget.h"
#include "summaryeditor.h"
#include "announcementeditor.h"
#include "mapeditor.h"
#include "npc_battle_editor.h"
#include "npc_normal_editor.h"
#include "scene_battle_editor.h"
#include "scene_normal_editor.h"

namespace ptzs {
    class EditArea : public QSplitter
    {
        Q_OBJECT
    public:
        explicit EditArea(QWidget *parent = nullptr);

    private:
        TreeWidget* tree;
        SummaryEditor *SEditor;
        AnnouncementEditor *AEditor;
        MapEditor *MEditor;
        NPC_battle_editor *NBEditor;
        NPC_normal_editor *NNEditor;
        scene_battle_editor *SBEditor;
        scene_normal_editor *SNEditor;
    signals:

    public slots:
        void onItemDoubleClicked(QTreeWidgetItem* item,int column);
};

}

#endif // EDITAREA_H
