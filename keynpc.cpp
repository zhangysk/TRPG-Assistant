#include "keynpc.h"

namespace ptzs {

int KeyNpc::dice(int n, int max)
{
    int r=0;
    for(int i=0;i<n;i++)
        r+=1+rand()%max;
    return r;
}

void KeyNpc::autoGenerate()
{
    attribute[liLiang]=dice(3,6);
    attribute[tiZhi]=dice(3,6);
    attribute[tiXing]=dice(2,6)+6;
    attribute[minJie]=dice(3,6);
    attribute[rongMao]=dice(3,6);
    attribute[zhiLi]=dice(2,6)+6;
    attribute[yiZhi]=dice(3,6);
    attribute[jiaoYu]=dice(3,6)+3;
    attribute[xingYun]=dice(1,20);

    attribute[shengMing]=attribute[tiXing]+attribute[zhiLi];
    attribute[moFa]=attribute[yiZhi];
    attribute[liZhi]=attribute[yiZhi]*5;
    attribute[xingYun]=attribute[xingYun];

}

} // namespace ptzs
