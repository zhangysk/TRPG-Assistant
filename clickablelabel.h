#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H
#include <QLabel>
#include <QMouseEvent>

namespace ptzs {

class ClickableLabel : public QLabel
{

    Q_OBJECT

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent *e);

};

} // namespace ptzs

#endif // CLICKABLELABEL_H
