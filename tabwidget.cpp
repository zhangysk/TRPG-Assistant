#include "tabwidget.h"

using namespace ptzs;

TabWidget::TabWidget()
{
    editingFiles=new QList<EditArea*>;
    editingFiles->append(new EditArea);
    addTab(editingFiles->last(),"sdf");
}
