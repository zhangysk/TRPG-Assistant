#ifndef KEYNPCEDITOR_H
#define KEYNPCEDITOR_H

#include <QTableWidget>
#include <QHeaderView>

namespace ptzs {

class KeyNpcEditor : public QTableWidget
{
    Q_OBJECT
public:
    explicit KeyNpcEditor(QWidget *parent = nullptr);

private:

signals:

public slots:
};

} // namespace ptzs

#endif // KEYNPCEDITOR_H
