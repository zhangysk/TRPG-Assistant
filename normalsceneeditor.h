#ifndef NORMALSCENEEDITOR_H
#define NORMALSCENEEDITOR_H

#include <QScrollArea>

namespace ptzs {

class NormalSceneEditor : public QScrollArea
{
    Q_OBJECT
public:
    explicit NormalSceneEditor(QWidget *parent = nullptr);

signals:

public slots:
};

} // namespace ptzs

#endif // NORMALSCENEEDITOR_H
