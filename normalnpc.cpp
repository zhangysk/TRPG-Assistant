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

NormalNpc::NormalNpc(QString &n, QString &i)
{
    name=n;
    geRenXinXi=i;
}

void NormalNpc::setAge(int a){
    age=a;
}

} // namespace ptzs
