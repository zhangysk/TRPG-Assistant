#include "treewidget.h"

using namespace ptzs;

TreeWidget::TreeWidget(QWidget *parent) : QTreeWidget(parent)
{
    setColumnCount(1);
    setHeaderHidden(true);
    QTreeWidgetItem* introduction=new QTreeWidgetItem(this,QStringList(QString("介绍")));
    QTreeWidgetItem* NPC=new QTreeWidgetItem(this,QStringList(QString("NPC")));
    QTreeWidgetItem* scene=new QTreeWidgetItem(this,QStringList(QString("场景")));
    addTopLevelItem(introduction);
    addTopLevelItem(NPC);
    addTopLevelItem(scene);
}
