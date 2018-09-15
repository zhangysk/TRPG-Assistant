#ifndef TABWIDGET_H
#define TABWIDGET_H

#include <QTableWidget>
#include "editarea.h"

namespace ptzs {
    class TabWidget : public QTabWidget
    {
    public:
        TabWidget();
        TabWidget(QString fileName);
        bool addFile();
        QList<EditArea*>* editingFiles;
    };
}

#endif // TABWIDGET_H
