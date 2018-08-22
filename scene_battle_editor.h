#ifndef SCENE_BATTLE_EDITOR_H
#define SCENE_BATTLE_EDITOR_H

#include <QWidget>
#include <QList>
#include <QLabel>
#include <QLineEdit>

namespace ptzs {

class scene_battle_editor : public QWidget
{
    Q_OBJECT
public:
    explicit scene_battle_editor(QWidget *parent = nullptr);

private:
    QList<QLabel*>* maps;

signals:

public slots:
};

} // namespace ptzs

#endif // SCENE_BATTLE_EDITOR_H
