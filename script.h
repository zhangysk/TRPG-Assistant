#ifndef SCRIPT_H
#define SCRIPT_H

#include <QList>
#include <QString>
#include "map.h"
#include "keynpc.h"
#include "normalnpc.h"
#include "battlescene.h"
#include "normalscene.h"
#include <QFile>
#include <QDebug>

namespace ptzs {

class Script
{
public:
    Script();
    Script(QString fileName);
    void setName(QString s){name=s;}
    void setSummary(QString s){summary=s;}
    void setAnnouncement(QString s){announcement=s;}
    void addMap(int index=-1){(index==-1)?maps->append(new Map):maps->insert(index,new Map);}
    void addBattleNPC(int index=-1){(index==-1)?BN->append(new KeyNpc):BN->insert(index,new KeyNpc);}
    void addNormalNPC(int index=-1){(index==-1)?NN->append(new NormalNpc):NN->insert(index,new NormalNpc);}
    void addBattleScene(int index=-1){(index==-1)?BS->append(new BattleScene):BS->insert(index,new BattleScene);}
    void addNormalScene(int index=-1){(index==-1)?NS->append(new NormalScene):NS->insert(index,new NormalScene);}
    QString getName(){return name;}
    QString getSummary(){return summary;}
    QString getAnnouncement(){return announcement;}
    Map* getMap(int index){return maps->at(index);}
    KeyNpc* getKeyNPC(int index){return BN->at(index);}
    NormalNpc* getNormalNPC(int index){return NN->at(index);}
    BattleScene* getBattleScene(int index){return BS->at(index);}
    NormalScene* getNormalScene(int index){return NS->at(index);}

private:
    QString name;
    QString summary;
    QString announcement;
    QList<Map*>* maps;
    QList<KeyNpc*>* BN;
    QList<NormalNpc*>* NN;
    QList<BattleScene*>* BS;
    QList<NormalScene*>* NS;
};

} // namespace ptzs

#endif // SCRIPT_H
