#include "keynpc.h"

namespace ptzs {

KeyNpc::KeyNpc()
{
    setName("");
    setAge(0);
    setSex(female);
    setGeRenXinXi("");
    setAvatar("");

    job=kuaiJiShi;
    liveArea="";
    bornArea="";

    renWuMiaoShu="";
    siNian_xinNian="";
    zhongYaoZhiRen="";
    yiYiFeiFanZhiDi="";
    baoGuiZhiWu="";
    teDian="";
    chuangShang_BaHen="";
    kongJu_kuangRe="";
    shenMiJuanZhou_ZhouWen_GuWenWu="";
    diSanLeiJieChu="";

    shengHuoShuiPing=shenWuFenWen;
    xieDaiWuPin="";

    for(int i=0;i<attributeNum;i++)
    {
        attribute[i]=0;
    }
    for(int i=0;i<skillNum;i++)
    {
        skill[i]=0;
    }
    for(int i=0;i<6;i++)
    {
        attribute[i]=0;
    }
    sWeapon w;
    w.ammo=0;
    w.damage=0;
    w.difficulty=0;
    w.mulfunction="";
    w.range=0;
    w.times=0;
    w.weapon="";
    for(int i=0;i<4;i++)
    {
        weapon[i]=w;
    }
}

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

QStringList KeyNpc::skillNames=QStringList()<<"kuaiJi"<<"renLeiXue"<<"guJia"<<"kaoGuXue"<<"yiShuYuGongYi_YanJi"<<"yiShuYuGongYi_WenXue"<<"yiShuYuGongYi_LiFa"<<"yiShuYuGongYi_MoLiSiWu"<<"yiShuYuGongYi_ShuFa"<<"yiShuYuGongYi_GeJuGeChang"<<"yiShuYuGongYi_MuGong"<<"yiShuYuGongYi_FenShuaYouQi"<<"yiShuYuGongYi_ChuYi"<<"yiShuYuGongYi_SheYing"<<"yiShuYuGongYi_WuDao"<<"yiShuYuGongYi_TaoGong"<<"yiShuYuGongYi_MeiShu"<<"yiShuYuGongYi_DiaoKe"<<"yiShuYuGongYi_WeiZao"<<"yiShuYuGongYi_ZhenKongChuiYeJi"<<"yiShuYuGongYi_GengZuo"<<"yiShuYuGongYi_YueQi"<<"yiShuYuGongYi_XunYang"<<"yiShuYuGongYi_DaZi"<<"yiShuYuGongYi_SuJi"<<"yiShuYuGongYi_ZhiTu"<<"meiHuo"<<"panPa"<<"dianNaoShiYong"<<"xinYongPingJi"<<"keSuLuShenHua"<<"qiaoZhuang"<<"shanBi"<<"qiCheJiaShi"<<"dianQiWeiXiu"<<"dianZiXue"<<"huaShu"<<"geDou_FuTou"<<"geDou_DouOu"<<"geDou_DianJu"<<"geDou_LianJia"<<"geDou_JiaoSha"<<"geDou_Mao"<<"geDou_Jian"<<"geDou_BianZi"<<"sheJi_gong"<<"sheJi_shouQiang"<<"sheJi_ZhongWuQi"<<"sheJi_HuoYanPenSheQi"<<"sheJi_JiGuanQiang"<<"sheJi_BuQiangXianDanQiang"<<"sheJi_ChongFengQiang"<<"jiJiu"<<"liShi"<<"weiHe"<<"tiaoYue"<<"qiTaYuYan_PlayerDefine_1"<<"qiTaYuYan_PlayerDefine_2"<<"muYu"<<"faLv"<<"tuShuGuanShiYong"<<"lingTing"<<"suoJiang"<<"jiXieWeiXiu"<<"yiXue"<<"ziRanXue"<<"lingHang"<<"shenMiXue"<<"caoZongZhongXingjiXie"<<"shuiFu"<<"jiaShi_ReQiQiu"<<"jiaShi_FeiTing"<<"jiaShi_LuoXuanJiangFeiJi"<<"jiaShi_PenQiFeiJi"<<"jiaShi_KeJi"<<"jiaShi_PenQiZhanDouji"<<"jiaShi_ZhiShengFeiJi"<<"jiaShi_Chuan"<<"xinliFenXi"<<"xinliXue"<<"qiShu"<<"keXue_TianWenXue"<<"keXue_ShengWuXue"<<"keXue_ZhiWuXue"<<"keXue_HuaXue"<<"keXue_MiMaXue"<<"keXue_GongChengXue"<<"keXue_WuZhengXue"<<"keXue_DiZhiXue"<<"keXue_ShuXue"<<"keXue_QiXiangXue"<<"keXue_YaoXue"<<"keXue_WuLiXue"<<"keXue_DongWuXue"<<"miaoShou"<<"zhenCha"<<"yinMiXingDong"<<"shengCun_ShaMo"<<"shengCun_HaiYang"<<"shengCun_JiDi"<<"shengCun_ShanDi"<<"youYong"<<"touZhi"<<"zhuiZong"<<"feiChangGuiJiNeng_DongWuXunYang"<<"feiChangGuijiNeng_PaoShu"<<"feiChangGuijiNeng_BaoPo"<<"feiChangGuijiNeng_QianShui"<<"feiChangGuijiNeng_CuiMian"<<"feiChangGuijiNeng_DuChun"<<"xueWen_PlayerDefine_1"<<"xueWen_PlayerDefine_2"<<"playerDefine_1"<<"playerDefine_2"<<"playerDefine_3"<<"renXuan"<<"sanJiao"<<"xing"<<"yuan"<<"fangKuai";
QStringList KeyNpc::attributeNames=QStringList()<<"力量"<<"体质"<<"体型"<<"敏捷"<<"容貌"<<"智力"<<"意志"<<"教育"<<"幸运"<<"生命值"<<"魔法值"<<"理智值"<<"移动力"<<"伤害加值"<<"体格";

} // namespace ptzs
