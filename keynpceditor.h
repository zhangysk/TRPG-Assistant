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
    QList<QLineEdit*> info,background,attribute,skill,weapon,skillName;
    QLineEdit *items;
    QTextEdit *discription;
    QComboBox *job,*sex,*livingStandard;
    ClickableLabel *avatar;

signals:

public slots:
    void setInfo(QString s);
    void setBackground(QString s);
    void setAssest(QString s);
    void setAttribute(QString s);
    void setSkill(QString s);
    void setWeapon(QString s);
    void setSkillName(QString s);
};

} // namespace ptzs

#endif // KEYNPCEDITOR_H
