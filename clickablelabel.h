#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H

#include <QLabel>
#include <QMouseEvent>

namespace ptzs {

class ClickableLabel : public QLabel
{

    Q_OBJECT

public:
    explicit ClickableLabel(QWidget *parent = nullptr);
    void setChange(bool _){change=_;}

private:
    bool change;
    QPixmap rawPic;
    bool scaled;

protected:
    void mouseReleaseEvent(QMouseEvent *e);
    void enterEvent(QEvent *e);
    void leaveEvent(QEvent *e);

signals:
    void clicked(ClickableLabel *self);
};

} // namespace ptzs

#endif // CLICKABLELABEL_H
