#ifndef BATTLESCENE_H
#define BATTLESCENE_H

#include <QStringList>

namespace ptzs {

class BattleScene
{
public:
    BattleScene();

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

#endif // BATTLESCENE_H
