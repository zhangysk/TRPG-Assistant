#ifndef FILEWIDGET_H
#define FILEWIDGET_H

#include <QWidget>

namespace ptzs {

class FileWidget : public QWidget
{
    Q_OBJECT
public:
    explicit FileWidget(QWidget *parent = nullptr);

signals:

public slots:
};

} // namespace ptzs

#endif // FILEWIDGET_H