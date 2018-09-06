#ifndef SCENEWIDGET_H
#define SCENEWIDGET_H

#include <QWidget>

namespace ptzs {

class SceneWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SceneWidget(QWidget *parent = nullptr);

signals:

public slots:
};

} // namespace ptzs

#endif // SCENEWIDGET_H