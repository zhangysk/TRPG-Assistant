#ifndef MAP_H
#define MAP_H

#include <QString>


namespace ptzs {

class Map
{
public:
    Map();
    QString getName(){return name;}
    QString getPicFile(){return picFile;}
    QString getIntroduction(){return introduction;}
    void setName(QString s){name=s;}
    void setPicFile(QString s){picFile=s;}
    void setIntroduction(QString s){introduction=s;}

private:
    QString name;
    QString picFile;
    QString introduction;

};

} // namespace ptzs

#endif // MAP_H
