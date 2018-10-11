#ifndef BATTLESCENE_H
#define BATTLESCENE_H

#include <QStringList>

namespace ptzs {

class BattleScene
{
public:
    BattleScene();

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
    QStringList* getPics(){return &pics;}
    QStringList* getPicInfo(){return &picInfo;}
    QStringList* getMusics(){return &musics;}
    QStringList* getMusicInfo(){return &musicInfo;}

};

} // namespace ptzs

#endif // BATTLESCENE_H
