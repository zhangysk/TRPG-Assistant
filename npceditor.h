#ifndef NPCEDITOR_H
#define NPCEDITOR_H

#include <QWidget>
#include <QLineEdit>

class NPCEditor : public QWidget
{
    Q_OBJECT
public:
    explicit NPCEditor(QWidget *parent = nullptr);

private:
    QLineEdit *infoLe[10],*nameLe,*headLe;

signals:

public slots:
};

#endif // NPCEDITOR_H
