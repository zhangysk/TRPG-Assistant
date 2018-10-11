#ifndef NORMALNPC_H
#define NORMALNPC_H

#include <QString>
#include <QDebug>

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
    QString getGeRenXinXi(){return geRenXinXi;}
    QString getAvatar(){return avatar;}
    int getAge(){return age;}
    esex getSex(){return sex;}

private:
    QString name;
    int age;
    esex sex;
    QString geRenXinXi;
    QString avatar;

public slots:
    void setName(QString s){name=s;}
    void setGeRenXinXi(QString s){geRenXinXi=s;}
    void setAvatar(QString s){avatar=s;}
    void setAge(int a);
    void setSex(esex s){sex=s;}

};

} // namespace ptzs

#endif // NORMALNPC_H
