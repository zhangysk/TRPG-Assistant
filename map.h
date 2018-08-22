#ifndef MAP_H
#define MAP_H

#include <QString>


namespace ptzs {

class Map
{
public:
    Map();

private:
    QString *name;
    QString *picFile;
    QString *introduction;

};

} // namespace ptzs

#endif // MAP_H
