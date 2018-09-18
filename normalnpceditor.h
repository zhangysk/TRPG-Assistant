#ifndef NORMALNPCEDITOR_H
#define NORMALNPCEDITOR_H

#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <QComboBox>
#include <QGridLayout>
#include <QFileDialog>
#include "data.h"
#include "clickablelabel.h"
#include "normalnpc.h"

namespace ptzs {

class NormalNpcEditor : public QWidget
{
    Q_OBJECT
public:
    explicit NormalNpcEditor(QWidget *parent = nullptr);

private:
    NormalNpc npc;
    QLineEdit *name,*_name;
    QLineEdit *sex;
    QComboBox *_sex;
    QLineEdit *age,*_age;
    QLineEdit *info;
    QTextEdit *_info;
    QLineEdit *avatar;
    ClickableLabel *_avatar;
    QGridLayout *layout;
    QPixmap pixmap;

signals:

public slots:
    void selectAvatarFile();
};

} // namespace ptzs

#endif // NORMALNPCEDITOR_H
