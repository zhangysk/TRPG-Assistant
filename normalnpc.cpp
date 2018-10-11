#include "normalnpc.h"

namespace ptzs {

NormalNpc::NormalNpc()
{
    name=("");
    setAge(0);
    sex=female;
    geRenXinXi=("");
    avatar=("");
}

void NormalNpc::setAge(int a){
    age=a;
}

} // namespace ptzs
