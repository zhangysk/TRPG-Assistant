#ifndef FILEWIDGET_H
#define FILEWIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include "clickablelabel.h"

namespace ptzs {

class FileWidget : public QWidget
{
    Q_OBJECT
public:
    explicit FileWidget(QWidget *parent = nullptr);
    ClickableLabel* openLabel(){return open;}
    ClickableLabel* newLabel(){return _new;}

private:
    QHBoxLayout *layout;
    ClickableLabel *open,*_new;

signals:

public slots:
};

} // namespace ptzs

#endif // FILEWIDGET_H
