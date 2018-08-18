#ifndef EDITAREA_H
#define EDITAREA_H

#include <QSplitter>
#include "treewidget.h"
#include "infoeditor.h"

namespace ptzs {
    class EditArea : public QSplitter
    {
        Q_OBJECT
    public:
        explicit EditArea(QWidget *parent = nullptr);

    private:
        QTreeWidget* tree;
        InfoEditor* infoEditor;
    signals:

    public slots:
};

}

#endif // EDITAREA_H
