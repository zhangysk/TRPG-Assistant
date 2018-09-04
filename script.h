#ifndef SCRIPT_H
#define SCRIPT_H

#include <QList>
#include <QString>
#include "map.h"
#include "npc_battle.h"
#include "npc_nomal.h"
#include "scene_battle.h"
#include "scene_normal.h"
#include <QFile>

namespace ptzs {

class Script
{
public:
    Script();
    Script(QString* fileName);
    QString* loadSummary();
    QString* loadAnnouncement();
    QList<Map*>* loadMaps();
    QList<NPC_battle*>* loadBN();
    QList<NPC_nomal*>* loadNN();
    QList<scene_battle*>* loadBS();
    QList<scene_normal*>* loadNS();
private:
    QString* name;
    QString* announcement;
    QList<Map*>* maps;
    QList<NPC_battle*>* BN;
    QList<NPC_nomal*>* NN;
    QList<scene_battle*>* BS;
    QList<scene_normal*>* NS;
};

} // namespace ptzs

#endif // SCRIPT_H
