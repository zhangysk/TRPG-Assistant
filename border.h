#ifndef BORDER_H
#define BORDER_H

#include <QWidget>

namespace ptzs {

class Border : public QWidget
{
    Q_OBJECT
public:
    explicit Border(QWidget *parent = nullptr);

signals:

public slots:
};

} // namespace ptzs

#endif // BORDER_H