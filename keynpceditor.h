#ifndef KEYNPCEDITOR_H
#define KEYNPCEDITOR_H

#include <QWidget>
#include <QGridLayout>
#include <QScrollArea>
#include <QLineEdit>
#include <QTextEdit>
#include <QComboBox>
#include "clickablelabel.h"
#include "keynpc.h"
#include "data.h"

namespace ptzs {

class KeyNpcEditor : public QScrollArea
{
    Q_OBJECT
public:
    explicit KeyNpcEditor(QWidget *parent = nullptr);

private:
    KeyNpc npc;
    QWidget *widget;
    QGridLayout *layout,*_layout;
    QList<QLineEdit*> infoTag,backgroundTag,assestTag,attributeTag,skillTag,weaponTag,type;
    QList<QLineEdit*> info,background,assest,attribute,skill,weapon,skillName;
    QTextEdit *discription;
    QComboBox *job,*sex;
    ClickableLabel *avatar;

signals:

public slots:
    void setInfo();
    void setBackground();
    void setAssest();
    void setAttribute();
    void setSkill();
    void setWeapon();
    void setSkillName();
};

} // namespace ptzs

#endif // KEYNPCEDITOR_H
