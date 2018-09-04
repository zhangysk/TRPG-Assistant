#ifndef SCENE_NORMAL_EDITOR_H
#define SCENE_NORMAL_EDITOR_H

#include <QScrollArea>

namespace ptzs {

class scene_normal_editor : public QScrollArea
{
    Q_OBJECT
public:
    explicit scene_normal_editor(QWidget *parent = nullptr);

signals:

public slots:
};

} // namespace ptzs

#endif // SCENE_NORMAL_EDITOR_H
