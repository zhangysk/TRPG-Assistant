#ifndef MAPEDITOR_H
#define MAPEDITOR_H

#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QFileDialog>
#include "data.h"
#include "clickablelabel.h"
#include "map.h"


namespace ptzs {

class MapEditor : public QWidget
{
    Q_OBJECT
public:
    explicit MapEditor(QWidget *parent = nullptr);
    void setMap(Map *m){map=m;}
    void setPixmap(const QPixmap &pic);

private:
    Map *map;
    QLineEdit *le;
    QTextEdit *te;
    ClickableLabel *label;
    QVBoxLayout *layout;
    QPixmap pixmap;

protected:
    void resizeEvent(QResizeEvent *size);

signals:

public slots:
    bool selectMapFile();
    void setMapName();
    void setMapInfo();

};

} // namespace ptzs

#endif // MAPEDITOR_H
