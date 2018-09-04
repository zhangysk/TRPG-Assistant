#include "script.h"

namespace ptzs {

Script::Script()
{
    maps=new QList<Map*>;
    BN=new QList<NPC_battle*>;
    NN=new QList<NPC_nomal*>;
    BS=new QList<scene_battle*>;
    NS=new QList<scene_normal*>;
}



} // namespace ptzs
