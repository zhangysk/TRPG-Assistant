#ifndef INFOWIDGET_H
#define INFOWIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include "clickablelabel.h"

namespace ptzs {

class InfoWidget : public QWidget
{
    Q_OBJECT
public:
    explicit InfoWidget(QWidget *parent = nullptr);
    ClickableLabel* summaryLabel(){return summary;}
    ClickableLabel* announcementLabel(){return announcement;}
    ClickableLabel* mapLabel(){return map;}

private:
    QHBoxLayout *layout;
    ClickableLabel *summary,*announcement,*map;

signals:

public slots:
};

} // namespace ptzs

#endif // INFOWIDGET_H
