#ifndef FILE_H
#define FILE_H

#include <QFile>
#include <QList>
#include <QString>
#include "map.h"
#include "npc_battle.h"
#include "npc_nomal.h"
#include "scene_battle.h"
#include "scene_normal.h"
#include "script.h"

namespace ptzs {

class File : public QFile
{
public:
    Script* loadScript();

private:
    QString fileName;

};

} // namespace ptzs

#endif // FILE_H
