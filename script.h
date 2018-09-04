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
    Script(QString fileName);
    void setName(QString s){name=s;}
    void setSummary(QString s){summary=s;}
    void setAnnouncement(QString s){announcement=s;}
    void addMap(int index=-1){(index==-1)?maps->insert(index,new Map):maps->append(new Map);}
    void addBattleNPC(int index=-1){(index==-1)?BN->insert(index,new NPC_battle):BN->append(new NPC_battle);}
    void addNormalNPC(int index=-1){(index==-1)?NN->insert(index,new NPC_nomal):NN->append(new NPC_nomal);}
    void addBattleScene(int index=-1){(index==-1)?BS->insert(index,new scene_battle):BS->append(new scene_battle);}
    void addNormalScene(int index=-1){(index==-1)?NS->insert(index,new scene_normal):NS->append(new scene_normal);}
    QString getName(){return name;}
    QString getSummary(){return summary;}
    QString getAnnouncement(){return announcement;}
    Map* getMap(int index){return maps->at(index);}
    NPC_battle* getBattleNPC(int index){return BN->at(index);}
    NPC_nomal* getNormalNPC(int index){return NN->at(index);}
    scene_battle* getBattleScene(int index){return BS->at(index);}
    scene_normal* getNormalScene(int index){return NS->at(index);}

private:
    QString name;
    QString summary;
    QString announcement;
    QList<Map*>* maps;
    QList<NPC_battle*>* BN;
    QList<NPC_nomal*>* NN;
    QList<scene_battle*>* BS;
    QList<scene_normal*>* NS;
};

} // namespace ptzs

#endif // SCRIPT_H
