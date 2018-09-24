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

class KeyNpcEditor : public QScrollArea
{
    Q_OBJECT
public:
    explicit KeyNpcEditor(QWidget *parent = nullptr);

private:
    QWidget *widget;
    QGridLayout *layout,*_layout;
    QLineEdit *tag,*type;
    QLineEdit *le;
    QTextEdit *te;
    ClickableLabel *avatar;

signals:

public slots:
};

} // namespace ptzs

#endif // KEYNPCEDITOR_H
