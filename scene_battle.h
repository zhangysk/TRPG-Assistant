#ifndef SCENE_BATTLE_H
#define SCENE_BATTLE_H

#include <QStringList>

namespace ptzs {

class scene_battle
{
public:
    scene_battle();

private:
    QStringList *pics;
    QStringList *picinfo;
    QStringList *musics;
    QStringList *musicinfo;

public:
    int picNum(){return pics->isEmpty()?0:pics->size();}
    int musicNum(){return musics->isEmpty()?0:musics->size();}
};

} // namespace ptzs

#endif // SCENE_BATTLE_H
