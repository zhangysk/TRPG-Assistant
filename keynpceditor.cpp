#include "keynpceditor.h"

namespace ptzs {

KeyNpcEditor::KeyNpcEditor(QWidget *parent) : QScrollArea(parent)
{
    widget=new QWidget(this);
    layout=new QGridLayout;
    _layout=new QGridLayout(this);

    for(int i=0;i<6;i++)
    {
        infoTag.append(new QLineEdit);
    }
    for(int i=0;i<10;i++)
    {
        backgroundTag.append(new QLineEdit);
    }
    for(int i=0;i<2;i++)
    {
        assestTag.append(new QLineEdit);
    }
    for(int i=0;i<16;i++)
    {
        attributeTag.append(new QLineEdit);
    }
    for(int i=0;i<118;i++)
    {
        skillTag.append(new QLineEdit);
    }
    for(int i=0;i<28;i++)
    {
        weaponTag.append(new QLineEdit);
    }
    for(int i=0;i<10;i++)
    {
        type.append(new QLineEdit);
    }

    for(int i=0;i<4;i++)
    {
        info.append(new QLineEdit);
    }
    for(int i=0;i<9;i++)
    {
        background.append(new QLineEdit);
    }
    for(int i=0;i<2;i++)
    {
        assest.append(new QLineEdit);
    }
    for(int i=0;i<16;i++)
    {
        attribute.append(new QLineEdit);
    }
    for(int i=0;i<114;i++)
    {
        skill.append(new QLineEdit);
    }
    for(int i=0;i<28;i++)
    {
        weapon.append(new QLineEdit);
    }
    for(int i=0;i<6;i++)
    {
        skillName.append(new QLineEdit);
    }

    discription=new QTextEdit(this);
    avatar=new ClickableLabel(this);
    job=new QComboBox(this);
    sex=new QComboBox(this);

    for(int i=0;i<6;i++)//infotag初始化
    {
        infoTag.at(i)->setReadOnly(true);
        infoTag.at(i)->setAlignment(Qt::AlignCenter);
        infoTag.at(i)->setFont(myFont);
    }
    for(int i=0;i<10;i++)//backgroundTag初始化
    {
        backgroundTag.at(i)->setReadOnly(true);
        backgroundTag.at(i)->setAlignment(Qt::AlignCenter);
        backgroundTag.at(i)->setFont(myFont);
    }
    for(int i=0;i<2;i++)//assestTag初始化
    {
        assestTag.at(i)->setReadOnly(true);
        assestTag.at(i)->setAlignment(Qt::AlignCenter);
        assestTag.at(i)->setFont(myFont);
    }
    for(int i=0;i<16;i++)//attributeTag初始化
    {
        attributeTag.at(i)->setReadOnly(true);
        attributeTag.at(i)->setAlignment(Qt::AlignCenter);
        attributeTag.at(i)->setFont(myFont);
    }
    for(int i=0;i<118;i++)//skillTag初始化
    {
        skillTag.at(i)->setReadOnly(true);
        skillTag.at(i)->setAlignment(Qt::AlignCenter);
        skillTag.at(i)->setFont(myFont);
    }
    for(int i=0;i<28;i++)//weaponTag初始化
    {
        weaponTag.at(i)->setReadOnly(true);
        weaponTag.at(i)->setAlignment(Qt::AlignCenter);
        weaponTag.at(i)->setFont(myFont);
    }
    for(int i=0;i<10;i++)//type初始化
    {
        type.at(i)->setReadOnly(true);
        type.at(i)->setAlignment(Qt::AlignCenter);
        type.at(i)->setFont(myFont);
    }
    for(int i=0;i<4;i++)//info初始化
    {
        info.at(i)->setAlignment(Qt::AlignCenter);
        info.at(i)->setFont(myFont);
    }
    for(int i=0;i<9;i++)//background初始化
    {
        background.at(i)->setAlignment(Qt::AlignCenter);
        background.at(i)->setFont(myFont);
    }
    for(int i=0;i<2;i++)//assest初始化
    {
        assest.at(i)->setAlignment(Qt::AlignCenter);
        assest.at(i)->setFont(myFont);
    }
    for(int i=0;i<16;i++)//attribute初始化
    {
        attribute.at(i)->setAlignment(Qt::AlignCenter);
        attribute.at(i)->setFont(myFont);
    }
    for(int i=0;i<114;i++)//skill初始化
    {
        skill.at(i)->setAlignment(Qt::AlignCenter);
        skill.at(i)->setFont(myFont);
        skill.at(i)->setInputMethodHints(Qt::ImhDigitsOnly);
    }
    for(int i=0;i<28;i++)//weapon初始化
    {
        weapon.at(i)->setAlignment(Qt::AlignCenter);
        weapon.at(i)->setFont(myFont);
    }
    for(int i=0;i<6;i++)//skillName初始化
    {
        skillName.at(i)->setAlignment(Qt::AlignCenter);
        skillName.at(i)->setFont(myFont);
    }
    discription->setFont(myFont);
    QStringList list;
    //向list中添加项目
    {
        list.append("会计师");
        list.append("杂技演员");
        list.append("戏剧演员");
        list.append("电影演员");
        list.append("中介调查员");
        list.append("精神病医生（古典）");
        list.append("动物训练师");
        list.append("古文物学家（原作向）");
        list.append("古董商");
        list.append("考古学家（原作向）");
        list.append("建筑师");
        list.append("艺术家");
        list.append("精神病院护工");
        list.append("运动员");
        list.append("作家（原作向）");
        list.append("酒保");
        list.append("猎人");
        list.append("书商");
        list.append("赏金猎人");
        list.append("拳击手/摔跤手");
        list.append("管家/侍者/女仆");
        list.append("神职人员");
        list.append("计算机程序员");
        list.append("黑客（现代）");
        list.append("牛仔");
        list.append("工匠");
        list.append("刺客");
        list.append("银行劫匪");
        list.append("打手");
        list.append("窃贼");
        list.append("欺诈师");
        list.append("独行大盗");
        list.append("女盗匪（古典）");
        list.append("赃物贩子");
        list.append("赝造者");
        list.append("走私者");
        list.append("混混");
        list.append("教团首领");
        list.append("除魅师（现代）");
        list.append("设计师");
        list.append("业余艺术爱好者（原作向）");
        list.append("潜水员");
        list.append("医生（原作向）");
        list.append("流浪者");
        list.append("私人司机");
        list.append("司机");
        list.append("出租车司机");
        list.append("编辑");
        list.append("政府官员");
        list.append("工程师");
        list.append("艺人");
        list.append("探险家（古典）");
        list.append("农民");
        list.append("联邦探员");
        list.append("消防员");
        list.append("驻外记者");
        list.append("法医");
        list.append("赌徒");
        list.append("黑老大");
        list.append("马仔");
        list.append("绅士/淑女");
        list.append("游民");
        list.append("勤杂护工");
        list.append("调查记者");
        list.append("通讯记者");
        list.append("法官");
        list.append("实验室助理");
        list.append("非熟练工人");
        list.append("伐木工");
        list.append("矿工");
        list.append("律师");
        list.append("图书馆管理员（原作向）");
        list.append("技师/技术工人");
        list.append("军官");
        list.append("传教士");
        list.append("登山家");
        list.append("博物馆管理员");
        list.append("音乐家");
        list.append("护士");
        list.append("神秘学家");
        list.append("旅行家");
        list.append("超心理学家");
        list.append("药剂师");
        list.append("摄影师");
        list.append("摄影记者");
        list.append("飞行员");
        list.append("特技飞行员（古典）");
        list.append("警察/警探（原作向）");
        list.append("巡逻警察");
        list.append("私家侦探");
        list.append("教授（原作向）");
        list.append("淘金客");
        list.append("性工作者");
        list.append("精神病学家");
        list.append("心理学家/心理分析学家");
        list.append("研究员");
        list.append("军舰海员");
        list.append("民用船海员");
        list.append("销售员");
        list.append("科学家");
        list.append("秘书");
        list.append("店老板");
        list.append("士兵/海军陆战队");
        list.append("间谍");
        list.append("学生/实习生");
        list.append("替身演员");
        list.append("部落成员");
        list.append("殡葬师");
        list.append("工会活动家");
        list.append("服务生");
        list.append("职员/主管");
        list.append("中/高层管理人员");
        list.append("狂热者");
        list.append("饲养员");
    }
    job->addItems(list);
    sex->addItem("男");
    sex->addItem("女");
    avatar->setSizePolicy(QSizePolicy::MinimumExpanding,QSizePolicy::MinimumExpanding);
    widget->setMinimumHeight(7000);
    setWidget(widget);
    _layout->addWidget(widget);
    widget->setLayout(layout);
    discription->setMaximumHeight(300);

    //infoTag设置文字
    {
        infoTag[0]->setText("姓名");
        infoTag[1]->setText("职业");
        infoTag[2]->setText("年龄");
        infoTag[3]->setText("性别");
        infoTag[4]->setText("居住地");
        infoTag[5]->setText("出生地");
    }
    //backgroundTag设置文字
    {
        backgroundTag[0]->setText("人物描述");
        backgroundTag[1]->setText("思念与信念:");
        backgroundTag[2]->setText("重要之人:");
        backgroundTag[3]->setText("意义非凡之地:");
        backgroundTag[4]->setText("宝贵之物:");
        backgroundTag[5]->setText("特点:");
        backgroundTag[6]->setText("创伤和疤痕:");
        backgroundTag[7]->setText("恐惧和狂热:");
        backgroundTag[8]->setText("神秘卷轴、咒文和古文物");
        backgroundTag[9]->setText("第三类接触");
    }
    //assestTag设置文字
    {
        assestTag[0]->setText("生活水平");
        assestTag[1]->setText("携带物品");
    }
    //attributeTag设置文字
    {
        attributeTag[0]->setText("力量");
        attributeTag[1]->setText("体质");
        attributeTag[2]->setText("体型");
        attributeTag[3]->setText("敏捷");
        attributeTag[4]->setText("容貌");
        attributeTag[5]->setText("智力");
        attributeTag[6]->setText("意志");
        attributeTag[7]->setText("教育");
        attributeTag[8]->setText("幸运");
        attributeTag[9]->setText("生命值");
        attributeTag[10]->setText("魔法值");
        attributeTag[11]->setText("理智值");
        attributeTag[12]->setText("幸运值");
        attributeTag[13]->setText("移动力");
        attributeTag[14]->setText("伤害加值");
        attributeTag[15]->setText("体格");
    }
    //skillTag设置文字
    {
        skillTag[0]->setText("会计");
        skillTag[1]->setText("人类学");
        skillTag[2]->setText("估价");
        skillTag[3]->setText("考古学");
        skillTag[4]->setText("艺术与工艺");
        skillTag[5]->setText("演技");
        skillTag[6]->setText("文学");
        skillTag[7]->setText("理发");
        skillTag[8]->setText("莫里斯舞");
        skillTag[9]->setText("书法");
        skillTag[10]->setText("歌剧歌唱");
        skillTag[11]->setText("木工");
        skillTag[12]->setText("粉刷油漆");
        skillTag[13]->setText("厨艺");
        skillTag[14]->setText("摄影");
        skillTag[15]->setText("舞蹈");
        skillTag[16]->setText("陶工");
        skillTag[17]->setText("美术");
        skillTag[18]->setText("雕刻");
        skillTag[19]->setText("伪造");
        skillTag[20]->setText("真空吹叶机");
        skillTag[21]->setText("耕作");
        skillTag[22]->setText("乐器");
        skillTag[23]->setText("驯养");
        skillTag[24]->setText("打字");
        skillTag[25]->setText("速记");
        skillTag[26]->setText("制图");
        skillTag[27]->setText("魅惑");
        skillTag[28]->setText("攀爬");
        skillTag[29]->setText("电脑使用（现代）");
        skillTag[30]->setText("信用评级");
        skillTag[31]->setText("克苏鲁神话");
        skillTag[32]->setText("乔装");
        skillTag[33]->setText("闪避");
        skillTag[34]->setText("汽车驾驶");
        skillTag[35]->setText("电气维修");
        skillTag[36]->setText("电子学（现代）");
        skillTag[37]->setText("话术");
        skillTag[38]->setText("格斗");
        skillTag[39]->setText("斧头");
        skillTag[40]->setText("斗殴");
        skillTag[41]->setText("电锯");
        skillTag[42]->setText("连枷");
        skillTag[43]->setText("绞杀");
        skillTag[44]->setText("茅");
        skillTag[45]->setText("剑");
        skillTag[46]->setText("鞭子");
        skillTag[47]->setText("射击");
        skillTag[48]->setText("弓");
        skillTag[49]->setText("手枪");
        skillTag[50]->setText("重武器");
        skillTag[51]->setText("火焰喷射器");
        skillTag[52]->setText("机关枪");
        skillTag[53]->setText("步枪/霰弹枪");
        skillTag[54]->setText("冲锋枪");
        skillTag[55]->setText("急救");
        skillTag[56]->setText("历史");
        skillTag[57]->setText("威吓");
        skillTag[58]->setText("跳跃");
        skillTag[59]->setText("其他语言");
        skillTag[60]->setText("母语");
        skillTag[61]->setText("法律");
        skillTag[62]->setText("图书馆使用");
        skillTag[63]->setText("聆听");
        skillTag[64]->setText("锁匠");
        skillTag[65]->setText("机械维修");
        skillTag[66]->setText("医学");
        skillTag[67]->setText("自然学");
        skillTag[68]->setText("领航");
        skillTag[69]->setText("神秘学");
        skillTag[70]->setText("操纵重型机械");
        skillTag[71]->setText("说服");
        skillTag[72]->setText("驾驶");
        skillTag[73]->setText("热气球");
        skillTag[74]->setText("飞艇");
        skillTag[75]->setText("螺旋桨飞机");
        skillTag[76]->setText("喷气飞机");
        skillTag[77]->setText("客机");
        skillTag[78]->setText("喷气战斗机");
        skillTag[79]->setText("直升飞机");
        skillTag[80]->setText("船");
        skillTag[81]->setText("心理分析");
        skillTag[82]->setText("心理学");
        skillTag[83]->setText("骑术");
        skillTag[84]->setText("科学");
        skillTag[85]->setText("天文学");
        skillTag[86]->setText("生物学");
        skillTag[87]->setText("植物学");
        skillTag[88]->setText("化学");
        skillTag[89]->setText("密码学");
        skillTag[90]->setText("工程学");
        skillTag[91]->setText("物证学");
        skillTag[92]->setText("地质学");
        skillTag[93]->setText("数学");
        skillTag[94]->setText("气象学");
        skillTag[95]->setText("药学");
        skillTag[96]->setText("物理学");
        skillTag[97]->setText("动物学");
        skillTag[98]->setText("妙手");
        skillTag[99]->setText("侦察");
        skillTag[100]->setText("隐秘行动");
        skillTag[101]->setText("生存");
        skillTag[102]->setText("沙漠");
        skillTag[103]->setText("海洋");
        skillTag[104]->setText("极地");
        skillTag[105]->setText("山地");
        skillTag[106]->setText("游泳");
        skillTag[107]->setText("投掷");
        skillTag[108]->setText("追踪");
        skillTag[109]->setText("非常规技能");
        skillTag[110]->setText("动物驯养");
        skillTag[111]->setText("炮术");
        skillTag[112]->setText("爆破");
        skillTag[113]->setText("潜水");
        skillTag[114]->setText("催眠");
        skillTag[115]->setText("读唇");
        skillTag[116]->setText("学问");
        skillTag[117]->setText("其他技能");
    }
    //weaponTag设置文字
    {
        weaponTag[0]->setText("武器名称");
        weaponTag[1]->setText("难度");
        weaponTag[2]->setText("伤害");
        weaponTag[3]->setText("范围");
        weaponTag[4]->setText("攻击次数");
        weaponTag[5]->setText("弹药");
        weaponTag[6]->setText("故障");
        weaponTag[7]->setText("武器名称");
        weaponTag[8]->setText("难度");
        weaponTag[9]->setText("伤害");
        weaponTag[10]->setText("范围");
        weaponTag[11]->setText("攻击次数");
        weaponTag[12]->setText("弹药");
        weaponTag[13]->setText("故障");
        weaponTag[14]->setText("武器名称");
        weaponTag[15]->setText("难度");
        weaponTag[16]->setText("伤害");
        weaponTag[17]->setText("范围");
        weaponTag[18]->setText("攻击次数");
        weaponTag[19]->setText("弹药");
        weaponTag[20]->setText("故障");
        weaponTag[21]->setText("武器名称");
        weaponTag[22]->setText("难度");
        weaponTag[23]->setText("伤害");
        weaponTag[24]->setText("范围");
        weaponTag[25]->setText("攻击次数");
        weaponTag[26]->setText("弹药");
        weaponTag[27]->setText("故障");
    }
    //type设置文字
    {
        type[0]->setText("基本信息");
        type[1]->setText("头像");
        type[2]->setText("背景故事");
        type[3]->setText("资产");
        type[4]->setText("人物属性");
        type[5]->setText("技能");
        type[6]->setText("武器（1）");
        type[7]->setText("武器（2）");
        type[8]->setText("武器（3）");
        type[9]->setText("武器（4）");
    }
    //人物信息布局
    {
        layout->addWidget(type[0],0,0,1,4);
        layout->addWidget(infoTag[0],1,0,1,2);
        layout->addWidget(info[0],1,2,1,2);
        layout->addWidget(infoTag[1],2,0,1,2);
        layout->addWidget(job,2,2,1,2);
        layout->addWidget(infoTag[2],3,0,1,2);
        layout->addWidget(info[1],3,2,1,2);
        layout->addWidget(infoTag[3],4,0,1,2);
        layout->addWidget(sex,4,2,1,2);
        layout->addWidget(infoTag[4],5,0,1,2);
        layout->addWidget(info[2],5,2,1,2);
        layout->addWidget(infoTag[5],6,0,1,2);
        layout->addWidget(info[3],6,2,1,2);
    }
    //头像布局
    {
        layout->addWidget(type[1],7,0,1,4);
        layout->addWidget(avatar,8,0,1,4);
    }
    //人物背景布局
    {
        layout->addWidget(type[2],9,0,1,4);
        layout->addWidget(backgroundTag[0],10,0,1,4);
        layout->addWidget(discription,11,0,1,4);
        for(int i=0;i<9;i++)
        {
            layout->addWidget(backgroundTag[i+1],12+i,0,1,2);
            layout->addWidget(background[i],12+i,2,1,2);
        }
    }
    //资产布局
    {
        layout->addWidget(type[3],21,0,1,4);
        layout->addWidget(assestTag[0],22,0,1,2);
        layout->addWidget(assest[0],22,2,1,2);
        layout->addWidget(assestTag[1],23,0,1,2);
        layout->addWidget(assest[1],23,2,1,2);
    }
    //人物属性布局
    {
        layout->addWidget(type[4],24,0,1,4);
        for(int i=0;i<16;i++)
        {
            layout->addWidget(attributeTag[i],25+i,0,1,2);
            layout->addWidget(attribute[i],25+i,2,1,2);
        }
    }
    //技能布局
    {
        layout->addWidget(type[5],41,0,1,4);
        for(int i=0;i<4;i++)
        {
            layout->addWidget(skillTag[i],42+i,0,1,2);
            layout->addWidget(skill[i],42+i,2,1,2);
        }
        layout->addWidget(skillTag[4],46,0,22,1);
        for(int i=0;i<22;i++)
        {
            layout->addWidget(skillTag[5+i],46+i,1,1,1);
            layout->addWidget(skill[4+i],46+i,2,1,2);
        }
        for(int i=0;i<11;i++)
        {
            layout->addWidget(skillTag[27+i],68+i,0,1,2);
            layout->addWidget(skill[26+i],68+i,2,1,2);
        }
        layout->addWidget(skillTag[38],79,0,8,1);
        for(int i=0;i<8;i++)
        {
            layout->addWidget(skillTag[39+i],79+i,1,1,1);
            layout->addWidget(skill[37+i],79+i,2,1,2);
        }
        layout->addWidget(skillTag[47],87,0,7,1);
        for(int i=0;i<7;i++)
        {
            layout->addWidget(skillTag[48+i],87+i,1,1,1);
            layout->addWidget(skill[45+i],87+i,2,1,2);
        }
        for(int i=0;i<4;i++)
        {
            layout->addWidget(skillTag[55+i],94+i,0,1,2);
            layout->addWidget(skill[52+i],94+i,2,1,2);
        }
        layout->addWidget(skillTag[59],98,0,2,1);
        layout->addWidget(skillName[0],98,1,1,1);
        layout->addWidget(skill[56],98,2,1,2);
        layout->addWidget(skillName[1],99,1,1,1);
        layout->addWidget(skill[57],99,2,1,2);
        for(int i=0;i<12;i++)
        {
            layout->addWidget(skillTag[60+i],100+i,0,1,2);
            layout->addWidget(skill[58+i],100+i,2,1,2);
        }
        layout->addWidget(skillTag[72],112,0,8,1);
        for(int i=0;i<8;i++)
        {
            layout->addWidget(skillTag[73+i],112+i,1,1,1);
            layout->addWidget(skill[70+i],112+i,2,1,2);
        }
        for(int i=0;i<3;i++)
        {
            layout->addWidget(skillTag[81+i],120+i,0,1,2);
            layout->addWidget(skill[78+i],120+i,2,1,2);
        }
        layout->addWidget(skillTag[84],123,0,13,1);
        for(int i=0;i<13;i++)
        {
            layout->addWidget(skillTag[85+i],123+i,1,1,1);
            layout->addWidget(skill[81+i],123+i,2,1,2);
        }
        for(int i=0;i<3;i++)
        {
            layout->addWidget(skillTag[98+i],136+i,0,1,2);
            layout->addWidget(skill[94+i],136+i,2,1,2);
        }
        layout->addWidget(skillTag[101],139,0,4,1);
        for(int i=0;i<4;i++)
        {
            layout->addWidget(skillTag[102+i],139+i,1,1,1);
            layout->addWidget(skill[97+i],139+i,2,1,2);
        }
        for(int i=0;i<3;i++)
        {
            layout->addWidget(skillTag[106+i],143+i,0,1,2);
            layout->addWidget(skill[101+i],143+i,2,1,2);
        }
        layout->addWidget(skillTag[109],146,0,6,1);
        for(int i=0;i<6;i++)
        {
            layout->addWidget(skillTag[110+i],146+i,1,1,1);
            layout->addWidget(skill[104+i],146+i,2,1,2);
        }
        layout->addWidget(skillTag[116],154,0,1,1);
        layout->addWidget(skillName[4],154,1,1,1);
        layout->addWidget(skill[112],154,2,1,2);
        layout->addWidget(skillName[5],155,1,1,1);
        layout->addWidget(skill[113],155,2,1,2);
    }
    //武器布局
    {
        for(int i=0;i<4;i++)
        {
            layout->addWidget(type[6+i],156+8*i,0,1,4);
            for(int j=0;j<7;j++)
            {
                layout->addWidget(weaponTag[i*7+j],157+8*i+j,0,1,2);
                layout->addWidget(weapon[i*7+j],157+8*i+j,2,1,2);

            }
        }
    }
    //连接信号与槽
    for(int i=0;i<4;i++)
    {
        connect(info[i],SIGNAL(textChanged(QString)),this,SLOT(setInfo()));
    }
}

void KeyNpcEditor::setInfo()
{/*
    switch(info.indexOf(sender()))
    {
        case 0:
    }*/
}

void KeyNpcEditor::setBackground()
{

}

void KeyNpcEditor::setAssest()
{

}

void KeyNpcEditor::setAttribute()
{

}

void KeyNpcEditor::setSkill()
{

}

void KeyNpcEditor::setWeapon()
{

}

void KeyNpcEditor::setSkillName()
{

}

} // namespace ptzs
