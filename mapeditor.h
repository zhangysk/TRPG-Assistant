#ifndef MAPEDITOR_H
#define MAPEDITOR_H

#include <QWidget>
#include <QList>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QTextEdit>
#include <QResizeEvent>
#include <QPushButton>
#include <QPixmap>
#include "map.h"

namespace ptzs {

class MapEditor : public QWidget
{
    Q_OBJECT
public:
    explicit MapEditor(QWidget *parent = nullptr);

private:
    int index;
    Map *map;
    QLineEdit *le;
    QTextEdit *te;
    QLabel *label;
    QVBoxLayout *layout;
    QPushButton *button;
    QPixmap *pixmap,*imgToShow;
    void resizeEvent(QResizeEvent *size);

signals:

public slots:
};

} // namespace ptzs

#endif // MAPEDITOR_H
