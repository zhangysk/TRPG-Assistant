#ifndef ANNOUNCEMENTEDITOR_H
#define ANNOUNCEMENTEDITOR_H

#include <QWidget>
#include <QGridLayout>
#include <QTextEdit>
#include <QPushButton>

namespace ptzs {

class AnnouncementEditor : public QWidget
{
    Q_OBJECT
public:
    explicit AnnouncementEditor(QWidget *parent = nullptr);

private:
    QGridLayout* layout;
    QTextEdit *te;
    QPushButton *button;

signals:

public slots:
};

} // namespace ptzs

#endif // ANNOUNSEMENTEDITOR_H
