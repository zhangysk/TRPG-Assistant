#include "keynpceditor.h"

namespace ptzs {

KeyNpcEditor::KeyNpcEditor(QWidget *parent) : QTableWidget(parent)
{
    setRowCount(43);
    setColumnCount(33);
    verticalHeader()->hide();
    horizontalHeader()->hide();
    setSpan(1,1,1,5);
    setSpan(2,3,1,3);
    setSpan(3,3,6,3);
    setSpan(2,5,7,1);
    setSpan(10,1,1,5);
    setSpan(11,1,1,5);
    setSpan(12,1,4,5);
    for(int i=16;i<23;i++)
    {
        setSpan(i,1,1,2);
        setSpan(i,3,3,1);
    }
    for(int i=23;i<27;i++)
        setSpan(i,1,1,5);
}

} // namespace ptzs
