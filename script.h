#ifndef SCRIPT_H
#define SCRIPT_H

#include <QString>
#include <QFileInfo>
#include <QXmlStreamWriter>
#include <QTextEdit>
#include "map.h"
#include "keynpc.h"
#include "battlescene.h"
#include "normalscene.h"

namespace ptzs {

class Script
{
public slots:
    void setName(QString s){name=s;}
    void setSummary(QString s){summary=s;}
    void setAnnouncement(QString s){announcement=s;}
    void addMap(int index=-1){(index==-1)?maps.append(new Map):maps.insert(index,new Map);}
    void addKeyNPC(int index=-1){(index==-1)?keyNpc.append(new KeyNpc):keyNpc.insert(index,new KeyNpc);}
    void addNormalNPC(int index=-1){(index==-1)?normalNpc.append(new NormalNpc):normalNpc.insert(index,new NormalNpc);}
    void addBattleScene(int index=-1){(index==-1)?battleScene.append(new BattleScene):battleScene.insert(index,new BattleScene);}
    void addNormalScene(int index=-1){(index==-1)?normalScene.append(new NormalScene):normalScene.insert(index,new NormalScene);}
    QString getName(){return name;}
    QString getSummary(){return summary;}
    QString getAnnouncement(){return announcement;}
    Map* getMap(int index){return maps.at(index);}
    KeyNpc* getKeyNPC(int index){return keyNpc.at(index);}
    NormalNpc* getNormalNPC(int index){return normalNpc.at(index);}
    BattleScene* getBattleScene(int index){return battleScene.at(index);}
    NormalScene* getNormalScene(int index){return normalScene.at(index);}
    int mapNum(){return maps.count();}
    int keyNpcNum(){return keyNpc.count();}
    int normalNpcNum(){return normalNpc.count();}
    int battleSceneNum(){return battleScene.count();}
    int normalSceneNum(){return normalScene.count();}
    void scriptSaveAll(QString path);
    void scriptSaveAllXml(QString path);

private:
    QString name;
    QString summary;
    QString announcement;
    QList<Map*> maps;
    QList<KeyNpc*> keyNpc;
    QList<NormalNpc*> normalNpc;
    QList<BattleScene*> battleScene;
    QList<NormalScene*> normalScene;
};

} // namespace ptzs

#endif // SCRIPT_H
