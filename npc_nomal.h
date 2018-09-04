#ifndef NPC_NOMAL_H
#define NPC_NOMAL_H

#include <QString>


namespace ptzs {

class NPC_nomal
{
public:
    enum esex
    {
        male,
        female
    };
    NPC_nomal();
    NPC_nomal(QString &n,QString &i);
    QString getName(){return name;}
    QString getInfo(){return info;}
    int getAge(){return age;}
    esex getSex(){return sex;}
    void setName(QString &s){name=s;}
    void setInfo(QString &s){info=s;}
    void setAge(int a){age=a;}
    void setSex(esex s){sex=s;}
private:
    QString name;
    QString info;
    int age;
    esex sex;

};

} // namespace ptzs

#endif // NPC_NOMAL_H
