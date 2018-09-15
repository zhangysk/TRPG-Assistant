#ifndef BORDER_H
#define BORDER_H

#include <QWidget>
#include <QMouseEvent>

namespace ptzs {

class Border : public QWidget
{
    Q_OBJECT
public:
    enum location
    {
        top,
        bottom,
        right,
        left,
        topRight,
        topLeft,
        bottomRight,
        bottomLeft,
    };
    explicit Border(QWidget *parent = nullptr);
    Border(location p,QWidget *parent);
    void setLoc(location p);

protected:
    void mousePressEvent(QMouseEvent *ev);
    void mouseMoveEvent(QMouseEvent *ev);

private:
    location loc;
    QPoint startPos;

signals:

public slots:
};

} // namespace ptzs

#endif // BORDER_H
