#ifndef NORMALNPC_H
#define NORMALNPC_H

#include <QString>


namespace ptzs {

class NormalNpc
{
public:
    enum esex
    {
        male,
        female
    };
    NormalNpc();
    NormalNpc(QString &n,QString &i);
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

#endif // NORMALNPC_H
