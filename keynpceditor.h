#ifndef KEYNPCEDITOR_H
#define KEYNPCEDITOR_H

#include <QWidget>
#include <QGridLayout>
#include <QScrollArea>
#include <QLineEdit>
#include <QTextEdit>
#include "clickablelabel.h"
#include "data.h"

namespace ptzs {

class KeyNpcEditor : public QWidget
{
    Q_OBJECT
public:
    explicit KeyNpcEditor(QWidget *parent = nullptr);

private:
    QWidget *widget;
    QScrollArea *scrollArea;
    QGridLayout *layout,*_layout;

signals:

public slots:
};

} // namespace ptzs

#endif // KEYNPCEDITOR_H
