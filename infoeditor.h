#ifndef INFOEDITOR_H
#define INFOEDITOR_H

#include <QWidget>
#include <QGridLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>

namespace ptzs {

class InfoEditor : public QWidget
{
    Q_OBJECT
public:
    explicit InfoEditor(QWidget *parent = nullptr);

private:
    QGridLayout* layout;
    QLineEdit *le1,*le2,*le3,*le4;
    QTextEdit *te1,*te2;
    QPushButton *button;

signals:

public slots:
};

} // namespace ptzs

#endif // INFOEDITOR_H
