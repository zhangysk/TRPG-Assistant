#ifndef NPC_BATTLE_EDITOR_H
#define NPC_BATTLE_EDITOR_H

#include <QWidget>

namespace ptzs {

class NPC_battle_editor : public QWidget
{
    Q_OBJECT
public:
    explicit NPC_battle_editor(QWidget *parent = nullptr);

signals:

public slots:
};

} // namespace ptzs

#endif // NPC_BATTLE_EDITOR_H