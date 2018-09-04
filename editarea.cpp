#include "editarea.h"
#include "treewidget.h"

using namespace ptzs;

EditArea::EditArea(QWidget *parent) : QSplitter(parent)
{
    tree=new TreeWidget(this);
    tree->setMinimumWidth(100);
    tree->setMaximumWidth(300);
    SEditor=new SummaryEditor(parent);
    addWidget(SEditor);
    AEditor=new AnnouncementEditor(parent);
    MEditor=new MapEditor(parent);
    NBEditor=new NPC_battle_editor(parent);
    NNEditor=new NPC_normal_editor(parent);
    SBEditor=new scene_battle_editor(parent);
    SNEditor=new scene_normal_editor(parent);
    script=new Script;
    setChildrenCollapsible(false);
    connect(tree,SIGNAL(itemDoubleClicked(QTreeWidgetItem*,int)),this,SLOT(onItemDoubleClicked(QTreeWidgetItem*,int)));
}

void EditArea::onItemDoubleClicked(QTreeWidgetItem *item, int column)
{
    if(item==tree->summary)
    {
        replaceWidget(1,SEditor);
    }

    else if(item==tree->announcement)
    {
        replaceWidget(1,AEditor);
    }

    else if(!(tree->map_list->isEmpty())&&tree->map_list->contains(item))
    {
        replaceWidget(1,MEditor);
        MEditor->selectMap(script->getMap(tree->map_list->indexOf(item)));
    }
    else if(item==tree->map_add)
    {
        tree->addMap();
    }

    else if(!(tree->NPC_battle_list->isEmpty())&&tree->NPC_battle_list->contains(item))
    {
        replaceWidget(1,NBEditor);
    }
    else if(item==tree->NPC_battle_add)
    {
        tree->addNPCBattle();
    }

    else if(!(tree->NPC_normal_list->isEmpty())&&tree->NPC_normal_list->contains(item))
    {
        replaceWidget(1,NNEditor);
    }
    else if(item==tree->NPC_normal_add)
    {
        tree->addNPCNormal();
    }

    else if(!(tree->scene_battle_list->isEmpty())&&tree->scene_battle_list->contains(item))
    {
        replaceWidget(1,SBEditor);
    }
    else if(item==tree->scene_battle_add)
    {
        tree->addSceneBattle();
    }

    else if(!(tree->scene_normal_list->isEmpty())&&tree->scene_normal_list->contains(item))
    {
        replaceWidget(1,SNEditor);
    }
    else if(item==tree->scene_normal_add)
    {
        tree->addSceneNormal();
    }
}
