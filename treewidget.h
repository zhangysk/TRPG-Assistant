#ifndef TREEWIDGET_H
#define TREEWIDGET_H

#include <QTreeWidget>

namespace ptzs {
    class TreeWidget : public QTreeWidget
    {
    public:
        explicit TreeWidget(QWidget *parent = nullptr);
    };
}


#endif // TREEWIDGET_H
