#ifndef SCENEPICSHOWER_H
#define SCENEPICSHOWER_H

#include <QWidget>
#include <QGridLayout>
#include <QLineEdit>
#include <QTextEdit>
#include <QLabel>

namespace ptzs {

class ScenePicShower : public QWidget
{
    Q_OBJECT
public:
    explicit ScenePicShower(QWidget *parent = nullptr);

private:
    QGridLayout *layout;
    QLineEdit *name,*nameEditor,*info;
    QTextEdit *infoEditor;
    QLabel *label;

signals:

public slots:
};

} // namespace ptzs

#endif // SCENEPICSHOWER_H
