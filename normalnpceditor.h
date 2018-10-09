#ifndef NORMALNPCEDITOR_H
#define NORMALNPCEDITOR_H

#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QComboBox>
#include <QGridLayout>
#include <QFileDialog>
#include <QScrollArea>
#include "data.h"
#include "clickablelabel.h"
#include "normalnpc.h"

namespace ptzs {

class NormalNpcEditor : public QScrollArea
{
    Q_OBJECT
public:
    explicit NormalNpcEditor(QWidget *parent = nullptr);

private:
    NormalNpc *npc;
    QWidget *widget;
    QLineEdit *name,*_name;
    QLineEdit *sex;
    QComboBox *_sex;
    QLineEdit *age,*_age;
    QLineEdit *info;
    QTextEdit *_info;
    QLineEdit *avatar;
    ClickableLabel *_avatar;
    QGridLayout *layout,*_layout;
    QPixmap pixmap;

signals:

public slots:
    void selectAvatarFile();
    void set();
};

} // namespace ptzs

#endif // NORMALNPCEDITOR_H
