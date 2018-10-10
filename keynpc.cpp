#include "keynpc.h"

namespace ptzs {

KeyNpc::KeyNpc()
{
    job=zaJiYanYuan;
    qDebug()<<job;
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

QStringList KeyNpc::skillNames=QStringList()<<"会计师"<<"杂技演员"<<"戏剧演员"<<"电影演员"<<"中介调查员"<<"精神病医生（古典）"<<"动物训练师"<<"古文物学家（原作向）"<<"古董商"<<"考古学家（原作向）"<<"建筑师"<<"艺术家"<<"精神病院护工"<<"运动员"<<"作家（原作向）"<<"酒保"<<"猎人"<<"书商"<<"赏金猎人"<<"拳击手/摔跤手"<<"管家/侍者/女仆"<<"神职人员"<<"计算机程序员"<<"黑客（现代）"<<"牛仔"<<"工匠"<<"刺客"<<"银行劫匪"<<"打手"<<"窃贼"<<"欺诈师"<<"独行大盗"<<"女盗匪（古典）"<<"赃物贩子"<<"赝造者"<<"走私者"<<"混混"<<"教团首领"<<"除魅师（现代）"<<"设计师"<<"业余艺术爱好者（原作向）"<<"潜水员"<<"医生（原作向）"<<"流浪者"<<"私人司机"<<"司机"<<"出租车司机"<<"编辑"<<"政府官员"<<"工程师"<<"艺人"<<"探险家（古典）"<<"农民"<<"联邦探员"<<"消防员"<<"驻外记者"<<"法医"<<"赌徒"<<"黑老大"<<"马仔"<<"绅士/淑女"<<"游民"<<"勤杂护工"<<"调查记者"<<"通讯记者"<<"法官"<<"实验室助理"<<"非熟练工人"<<"伐木工"<<"矿工"<<"律师"<<"图书馆管理员（原作向）"<<"技师/技术工人"<<"军官"<<"传教士"<<"登山家"<<"博物馆管理员"<<"音乐家"<<"护士"<<"神秘学家"<<"旅行家"<<"超心理学家"<<"药剂师"<<"摄影师"<<"摄影记者"<<"飞行员"<<"特技飞行员（古典）"<<"警察/警探（原作向）"<<"巡逻警察"<<"私家侦探"<<"教授（原作向）"<<"淘金客"<<"性工作者"<<"精神病学家"<<"心理学家/心理分析学家"<<"研究员"<<"军舰海员"<<"民用船海员"<<"销售员"<<"科学家"<<"秘书"<<"店老板"<<"士兵/海军陆战队"<<"间谍"<<"学生/实习生"<<"替身演员"<<"部落成员"<<"殡葬师"<<"工会活动家"<<"服务生"<<"职员/主管"<<"中/高层管理人员"<<"狂热者"<<"饲养员";
QStringList KeyNpc::attributeNames=QStringList()<<"力量"<<"体质"<<"体型"<<"敏捷"<<"容貌"<<"智力"<<"意志"<<"教育"<<"幸运"<<"生命值"<<"魔法值"<<"理智值"<<"移动力"<<"伤害加值"<<"体格";

} // namespace ptzs
