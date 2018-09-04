#ifndef MAPEDITOR_H
#define MAPEDITOR_H

#include <QWidget>
#include <QList>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QResizeEvent>
#include <QPushButton>
#include <QPixmap>
#include <QFileDialog>
#include "clickablelabel.h"
#include "script.h"

namespace ptzs {

class MapEditor : public QWidget
{
    Q_OBJECT
public:
    explicit MapEditor(QWidget *parent = nullptr);
    void selectMap(Map *map);
    void setPixmap(const QPixmap &pic);

private:
    int index;
    QLineEdit *le;
    QTextEdit *te;
    ClickableLabel *label;
    QVBoxLayout *layout;
    QPushButton *button;
    QPixmap pixmap,imgToShow;
    void resizeEvent(QResizeEvent *size);

signals:

public slots:
    bool selectMapFile();
};

} // namespace ptzs

#endif // MAPEDITOR_H
