#include "script.h"


namespace ptzs {

Script::Script()
{
    maps=new QList<Map*>;
    BN=new QList<KeyNpc*>;
    NN=new QList<NormalNpc*>;
    BS=new QList<BattleScene*>;
    NS=new QList<NormalScene*>;
}



} // namespace ptzs
