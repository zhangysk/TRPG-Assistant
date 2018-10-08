#ifndef KEYNPC_H
#define KEYNPC_H

#include "normalnpc.h"
#include <QString>
#include <QStringList>

namespace ptzs {

class KeyNpc : public NormalNpc
{
public:
    enum eJob
    {
        kuaiJiShi,
        zaJiYanYuan,
        xiJuYanYuan,
        dianYingYanYuan,
        zhongJieDiaoChaYuan,
        jingShenBingYiSheng,
        dongWuXunLianShi,
        guWenWuXueJia,
        guDongShang,
        kaoGuXueJia,
        jianZhuShi,
        yiShuJia,
        jingShenBingYuanHuGong,
        yunDongYuan,
        zuoJia,
        jiuBao,
        lieRen,
        shuShang,
        shangJinLieRen,
        quanJiShou_Shuaijiaoshou,
        guanJia_ShiZhe_NvPu,
        shenZhiRenYuan,
        jiSuanJiChengXuYuan,
        heiKe,
        niuZai,
        gongJiang,
        ciKe,
        yinHangJieFei,
        daShou,
        qieZei,
        qiZhaShi,
        duXingDaDao,
        nvDaoFei,
        zangWuFanZi,
        yanZaoZhe,
        zouSiZhe,
        hunHun,
        jiaoTuanShouLing,
        chuMeishi,
        sheJiShi,
        yeYuYiShuAiHaoZhe,
        qianShuiYuan,
        yiSheng,
        liuLangZhe,
        siRenSiJi,
        siJi,
        chuZuCheSiJi,
        bianJi,
        zhengFuGuanYuan,
        gongChengShi,
        yiRen,
        tanXianJia,
        nongMin,
        lianBangTanYuan,
        xiaoFangYuan,
        zhuWaiJiZhe,
        faYi,
        duTu,
        heiLaoDa,
        naZai,
        shenShi_ShuNv,
        youMin,
        qinZaHuGong,
        diaoChaJiZhe,
        tongXunJiZhe,
        faGuan,
        shiYanShiZhuLi,
        feiShuLianGongRen,
        faMuGong,
        kuangGong,
        lvShi,
        tuShuGuanGuanLiYuan,
        jiShi_JiShuGongRen,
        junGuan,
        chuanJiaoShi,
        dengShanJia,
        boWuGuanGuanLiYuan,
        yinYueJia,
        huShi,
        shenMiXueJia,
        lvXingJia,
        chaoXinLiXueJia,
        yaoJiShi,
        sheYingShi,
        sheYingJiZhe,
        feiXingYuan,
        teJiFeiXingYuan,
        jingCha_JingTan,
        junLuoJingCha,
        siJiaZhenTan,
        jiaoShou,
        taoJinKe,
        xingGongZuoZhe,
        jingShenBingXueJia,
        XinLiXueJia_XinLiFenXiXueJia,
        yanJiuYuan,
        junJianHaiYuan,
        minYongChuanHaiYuan,
        xiaoShouYuan,
        keXueJia,
        miShu,
        dianLaoBan,
        shiBing_HaiJunLuZhanDui,
        jianDie,
        xueSheng_ShiXiSheng,
        tiShenYanYuan,
        buLuoChengYuan,
        binZangShi,
        gongHuiHuoDongJia,
        fuWuSheng,
        zhiYuan_ZhuGuan,
        zhong_GaoCengGuanLiRenYuan,
        kuangReZhe,
        siYangYuan,
        jobNum
    };
    enum eLivingStantard
    {
        shenWuFenWen,
        pinQiong,
        biaoZhun,
        xiaoKang,
        fuYu,
        haoFu,
        livingStantardNum
    };
    enum eAttribute
    {
        liLiang,
        tiZhi,
        tiXing,
        minJie,
        rongMao,
        zhiLi,
        yiZhi,
        jiaoYu,
        xingYun,
        shengMing,
        moFa,
        liZhi,
        yiDong,
        shangHaiJiaCheng,
        tiGe,
        attributeNum
    };
    enum eSkill
    {
        kuaiJi,
        renLeiXue,
        guJia,
        kaoGuXue,
        yiShuYuGongYi_YanJi,
        yiShuYuGongYi_WenXue,
        yiShuYuGongYi_LiFa,
        yiShuYuGongYi_MoLiSiWu,
        yiShuYuGongYi_ShuFa,
        yiShuYuGongYi_GeJuGeChang,
        yiShuYuGongYi_MuGong,
        yiShuYuGongYi_FenShuaYouQi,
        yiShuYuGongYi_ChuYi,
        yiShuYuGongYi_SheYing,
        yiShuYuGongYi_WuDao,
        yiShuYuGongYi_TaoGong,
        yiShuYuGongYi_MeiShu,
        yiShuYuGongYi_DiaoKe,
        yiShuYuGongYi_WeiZao,
        yiShuYuGongYi_ZhenKongChuiYeJi,
        yiShuYuGongYi_GengZuo,
        yiShuYuGongYi_YueQi,
        yiShuYuGongYi_XunYang,
        yiShuYuGongYi_DaZi,
        yiShuYuGongYi_SuJi,
        yiShuYuGongYi_ZhiTu,
        meiHuo,
        panPa,
        dianNaoShiYong,
        xinYongPingJi,
        keSuLuShenHua,
        qiaoZhuang,
        shanBi,
        qiCheJiaShi,
        dianQiWeiXiu,
        dianZiXue,
        huaShu,
        geDou_FuTou,
        geDou_DouOu,
        geDou_DianJu,
        geDou_LianJia,
        geDou_JiaoSha,
        geDou_Mao,
        geDou_Jian,
        geDou_BianZi,
        sheJi_gong,
        sheJi_shouQiang,
        sheJi_ZhongWuQi,
        sheJi_HuoYanPenSheQi,
        sheJi_JiGuanQiang,
        sheJi_BuQiangXianDanQiang,
        sheJi_ChongFengQiang,
        jiJiu,
        liShi,
        weiHe,
        tiaoYue,
        qiTaYuYan_PlayerDefine_1,
        qiTaYuYan_PlayerDefine_2,
        muYu,
        faLv,
        tuShuGuanShiYong,
        lingTing,
        suoJiang,
        jiXieWeiXiu,
        yiXue,
        ziRanXue,
        lingHang,
        shenMiXue,
        caoZongZhongXingjiXie,
        shuiFu,
        jiaShi_ReQiQiu,
        jiaShi_FeiTing,
        jiaShi_LuoXuanJiangFeiJi,
        jiaShi_PenQiFeiJi,
        jiaShi_KeJi,
        jiaShi_PenQiZhanDouji,
        jiaShi_ZhiShengFeiJi,
        jiaShi_Chuan,
        xinliFenXi,
        xinliXue,
        qiShu,
        keXue_TianWenXue,
        keXue_ShengWuXue,
        keXue_ZhiWuXue,
        keXue_HuaXue,
        keXue_MiMaXue,
        keXue_GongChengXue,
        keXue_WuZhengXue,
        keXue_DiZhiXue,
        keXue_ShuXue,
        keXue_QiXiangXue,
        keXue_YaoXue,
        keXue_WuLiXue,
        keXue_DongWuXue,
        miaoShou,
        zhenCha,
        yinMiXingDong,
        shengCun_ShaMo,
        shengCun_HaiYang,
        shengCun_JiDi,
        shengCun_ShanDi,
        youYong,
        touZhi,
        zhuiZong,
        feiChangGuiJiNeng_DongWuXunYang,
        feiChangGuijiNeng_PaoShu,
        feiChangGuijiNeng_BaoPo,
        feiChangGuijiNeng_QianShui,
        feiChangGuijiNeng_CuiMian,
        feiChangGuijiNeng_DuChun,
        xueWen_PlayerDefine_1,
        xueWen_PlayerDefine_2,
        playerDefine_1,
        playerDefine_2,
        playerDefine_3,
        renXuan,
        sanJiao,
        xing,
        yuan,
        fangKuai,
        skillNum
    };
    struct sWeapon
    {
        QString weapon;
        int difficulty;
        int damage;
        int range;
        int times;
        int ammo;
        QString mulfunction;
    };
    static int dice(int n,int max);
    static QStringList skillNames;
    static QStringList attributeNames;

    void autoGenerate();
    eJob getJob(){return job;}
    QString getLiveArea(){return liveArea;}
    QString getBornArea(){return bornArea;}

    QString getRenWuMiaoShu(){return renWuMiaoShu;}
    QString getSiNian_xinNian(){return siNian_xinNian;}
    QString getZhongYaoZhiRen(){return zhongYaoZhiRen;}
    QString getYiYiFeiFanZhiDi(){return yiYiFeiFanZhiDi;}
    QString getBaoGuiZhiWu(){return baoGuiZhiWu;}
    QString getTeDian(){return teDian;}
    QString getChuangShang_BaHen(){return chuangShang_BaHen;}
    QString getKongJu_kuangRe(){return kongJu_kuangRe;}
    QString getShenMiJuanZhou_ZhouWen_GuWenWu(){return shenMiJuanZhou_ZhouWen_GuWenWu;}
    QString getDiSanLeiJieChu(){return diSanLeiJieChu;}

    eLivingStantard getShengHuoShuiPing(){return shengHuoShuiPing;}
    QString getXieDaiWuPin(){return xieDaiWuPin;}

    int getAttribute(eAttribute a){return attribute[a];}
    int getSkill(eSkill a){return skill[a];}
    QString getSkillName(int i){return skillName[i];}

    sWeapon getWeapon(int n){return weapon[n];}

    void setJob(eJob a){job=a;}
    void setLiveArea(QString a){liveArea=a;}
    void setBornArea(QString a){bornArea=a;}

    void setRenWuMiaoShu(QString a){renWuMiaoShu=a;}
    void setSiNian_xinNian(QString a){siNian_xinNian=a;}
    void setZhongYaoZhiRen(QString a){zhongYaoZhiRen=a;}
    void setYiYiFeiFanZhiDi(QString a){yiYiFeiFanZhiDi=a;}
    void setBaoGuiZhiWu(QString a){baoGuiZhiWu=a;}
    void setTeDian(QString a){teDian=a;}
    void setChuangShang_BaHen(QString a){chuangShang_BaHen=a;}
    void setKongJu_kuangRe(QString a){kongJu_kuangRe=a;}
    void setShenMiJuanZhou_ZhouWen_GuWenWu(QString a){shenMiJuanZhou_ZhouWen_GuWenWu=a;}
    void setDiSanLeiJieChu(QString a){diSanLeiJieChu=a;}

    void setShengHuoShuiPing(eLivingStantard a){shengHuoShuiPing=a;}
    void setXieDaiWuPin(QString a){xieDaiWuPin=a;}

    void setAttribute(eAttribute n,int a){attribute[n]=a;}
    void setSkill(eSkill n,int a){skill[n]=a;}
    void setSkillName(int i,QString s){skillName[i]=s;}

    void setWeapon(int n,sWeapon a){weapon[n]=a;}


private:
    eJob job;
    QString liveArea;
    QString bornArea;

    QString renWuMiaoShu;
    QString siNian_xinNian;
    QString zhongYaoZhiRen;
    QString yiYiFeiFanZhiDi;
    QString baoGuiZhiWu;
    QString teDian;
    QString chuangShang_BaHen;
    QString kongJu_kuangRe;
    QString shenMiJuanZhou_ZhouWen_GuWenWu;
    QString diSanLeiJieChu;

    eLivingStantard shengHuoShuiPing;
    QString xieDaiWuPin;

    int attribute[attributeNum];
    int skill[skillNum];
    QString skillName[6];

    sWeapon weapon[4];

};

} // namespace ptzs

#endif // KEYNPC_H
