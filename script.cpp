#include "script.h"

namespace ptzs {

Script::Script()
{

}

Script::Script(QString* fileName)
{
    QFile f(fileName);
    QString str(f.readAll());
    name=new QString(str.indexOf())
}

} // namespace ptzs
