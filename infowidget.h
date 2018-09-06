#ifndef INFOWIDGET_H
#define INFOWIDGET_H

#include <QWidget>

namespace ptzs {

class InfoWidget : public QWidget
{
    Q_OBJECT
public:
    explicit InfoWidget(QWidget *parent = nullptr);

signals:

public slots:
};

} // namespace ptzs

#endif // INFOWIDGET_H