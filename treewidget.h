#ifndef TREEWIDGET_H
#define TREEWIDGET_H

#include <QTreeWidget>

namespace ptzs {
    class TreeWidget : public QTreeWidget
    {
    public:
        explicit TreeWidget(QWidget *parent = nullptr);
        void addMap();
        void addNPCBattle();
        void addNPCNormal();
        void addSceneBattle();
        void addSceneNormal();
        QTreeWidgetItem* introduction;
            QTreeWidgetItem* summary;
            QTreeWidgetItem* announcement;
            QTreeWidgetItem* map;
                QList<QTreeWidgetItem*>* map_list;
                QTreeWidgetItem* map_add;
        QTreeWidgetItem* NPC;
            QTreeWidgetItem* NPC_battle;
                QList<QTreeWidgetItem*>* NPC_battle_list;
                QTreeWidgetItem* NPC_battle_add;
            QTreeWidgetItem* NPC_normal;
                QList<QTreeWidgetItem*>* NPC_normal_list;
                QTreeWidgetItem* NPC_normal_add;
        QTreeWidgetItem* scene;
            QTreeWidgetItem* scene_battle;
                QList<QTreeWidgetItem*>* scene_battle_list;
                QTreeWidgetItem* scene_battle_add;
            QTreeWidgetItem* scene_normal;
                QList<QTreeWidgetItem*>* scene_normal_list;
                QTreeWidgetItem* scene_normal_add;

    private:

    public slots:
    };
}


#endif // TREEWIDGET_H
