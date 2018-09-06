#ifndef NPCWIDGET_H
#define NPCWIDGET_H

#include <QWidget>

namespace ptzs {

class NpcWidget : public QWidget
{
    Q_OBJECT
public:
    explicit NpcWidget(QWidget *parent = nullptr);

signals:

public slots:
};

} // namespace ptzs

#endif // NPCWIDGET_H