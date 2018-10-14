#ifndef BATTLESCENE_H
#define BATTLESCENE_H

#include <QStringList>

namespace ptzs {

class BattleScene
{
public:
    BattleScene(const QString &n="",const QString &i="");

private:
    QString name;
    QString intro;
    QStringList pics;
    QStringList picInfo;
    QStringList musics;
    QStringList musicInfo;

public:
    int picNum(){return pics.isEmpty()?0:pics.size();}
    int musicNum(){return musics.isEmpty()?0:musics.size();}
    QString getName(){return name;}
    QString getIntro(){return intro;}
    QString getPics(int index){return pics[index];}
    QString getPicInfo(int index){return picInfo[index];}
    QString getMusics(int index){return musics[index];}
    QString getMusicInfo(int index){return musicInfo[index];}
    void setName(const QString &s){name=s;}
    void setIntro(const QString &s){intro=s;}
    void setPic(int index,const QString &s){pics[index]=s;}
    void setPicInfo(int index,const QString &s){picInfo[index]=s;}
    void setMusic(int index,const QString &s){musics[index]=s;}
    void setMusicInfo(int index,const QString &s){musicInfo[index]=s;}
    void addPic(const QString &f="",const QString &i=""){pics.append(f);picInfo.append(i);}
    void addMusic(const QString &m="",const QString &i=""){musics.append(m);musicInfo.append(i);}
};

} // namespace ptzs

#endif // BATTLESCENE_H
