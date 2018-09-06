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
    property[liLiang]=dice(3,6);
    property[tiZhi]=dice(3,6);
    property[tiXing]=dice(2,6)+6;
    property[minJie]=dice(3,6);
    property[rongMao]=dice(3,6);
    property[zhiLi]=dice(2,6)+6;
    property[yiZhi]=dice(3,6);
    property[jiaoYu]=dice(3,6)+3;
    property[xingYun]=dice(1,20);

    value[shengMing_CUR]=value[shengMing_MAX]=property[tiXing]+property[zhiLi];
    value[moFa_CUR]=value[moFa_MAX]=property[yiZhi];
    value[liZhi_CUR]=value[liZhi_MAX]=property[yiZhi]*5;
    value[xingYun_CUR]=value[xingYun_MAX]=property[xingYun];

}

} // namespace ptzs
