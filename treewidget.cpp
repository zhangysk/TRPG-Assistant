#include "treewidget.h"

using namespace ptzs;

TreeWidget::TreeWidget(QWidget *parent) : QTreeWidget(parent)
{
    setColumnCount(1);
    setHeaderHidden(true);
    introduction=new QTreeWidgetItem(this,QStringList(QString("介绍")));
    {
        summary=new QTreeWidgetItem(QStringList(QString("剧本概要")));
        introduction->addChild(summary);
        announcement=new QTreeWidgetItem(QStringList(QString("公告信息")));
        introduction->addChild(announcement);
        map=new QTreeWidgetItem(QStringList(QString("地图")));
        {
            map_list=new QList<QTreeWidgetItem*>;
            map->addChildren(*map_list);
            map_add=new QTreeWidgetItem(QStringList(QString("添加地图")));
            map->addChild(map_add);
        }
        introduction->addChild(map);
    }
    NPC=new QTreeWidgetItem(this,QStringList(QString("NPC")));
    {
        NPC_battle=new QTreeWidgetItem(QStringList(QString("战斗NPC")));
        {
            NPC_battle_list=new QList<QTreeWidgetItem*>;
            NPC_battle->addChildren(*NPC_battle_list);
            NPC_battle_add=new QTreeWidgetItem(QStringList(QString("添加战斗NPC")));
            NPC_battle->addChild(NPC_battle_add);
        }
        NPC->addChild(NPC_battle);
        NPC_normal=new QTreeWidgetItem(QStringList(QString("普通NPC")));
        {
            NPC_normal_list=new QList<QTreeWidgetItem*>;
            NPC_normal->addChildren(*NPC_normal_list);
            NPC_normal_add=new QTreeWidgetItem(QStringList(QString("添加普通NPC")));
            NPC_normal->addChild(NPC_normal_add);
        }
        NPC->addChild(NPC_normal);
    }
    scene=new QTreeWidgetItem(this,QStringList(QString("场景")));
    {
        scene_battle=new QTreeWidgetItem(QStringList(QString("战斗场景")));
        {
            scene_battle_list=new QList<QTreeWidgetItem*>;
            scene_battle->addChildren(*scene_battle_list);
            scene->addChild(scene_battle);
            scene_battle_add=new QTreeWidgetItem(QStringList(QString("添加战斗场景")));
            scene_battle->addChild(scene_battle_add);
        }
        scene_normal=new QTreeWidgetItem(QStringList(QString("普通场景")));
        {
            scene_normal_list=new QList<QTreeWidgetItem*>;
            scene_normal->addChildren(*scene_normal_list);
            scene_normal_add=new QTreeWidgetItem(QStringList(QString("添加普通场景")));
            scene_normal->addChild(scene_normal_add);
        }
        scene->addChild(scene_normal);
    }
}

void TreeWidget::addMap()
{
    map_list->append(new QTreeWidgetItem(QStringList(QString("未命名"))));
    map->addChild(map_list->last());
}

void TreeWidget::addNPCBattle()
{
    NPC_battle_list->append(new QTreeWidgetItem(QStringList(QString("未命名"))));
    NPC_battle->addChild(NPC_battle_list->constLast());
}

void TreeWidget::addNPCNormal()
{
    NPC_normal_list->append(new QTreeWidgetItem(QStringList(QString("未命名"))));
    NPC_normal->addChild(NPC_normal_list->last());
}

void TreeWidget::addSceneBattle()
{
    scene_battle_list->append(new QTreeWidgetItem(QStringList(QString("未命名"))));
    scene_battle->addChild(scene_battle_list->last());
}

void TreeWidget::addSceneNormal()
{
    scene_normal_list->append(new QTreeWidgetItem(QStringList(QString("未命名"))));
    scene_normal->addChild(scene_normal_list->last());
}
