#include "editarea.h"

using namespace ptzs;

EditArea::EditArea(QWidget *parent) : QSplitter(parent)
{
    tree=new TreeWidget(this);
    tree->setMinimumWidth(100);
    tree->setMaximumWidth(300);
    infoEditor=new InfoEditor(this);
    setChildrenCollapsible(false);
}

