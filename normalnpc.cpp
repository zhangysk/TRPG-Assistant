#include "normalnpc.h"

namespace ptzs {

NormalNpc::NormalNpc()
{
    name=("");
    age=0;
    sex=female;
    geRenXinXi=("");
    avatar=("");
}

NormalNpc::NormalNpc(QString &n, QString &i)
{
    name=n;
    geRenXinXi=i;
}

} // namespace ptzs
