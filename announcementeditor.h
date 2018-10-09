#ifndef ANNOUNCEMENTEDITOR_H
#define ANNOUNCEMENTEDITOR_H

#include <QWidget>
#include <QGridLayout>
#include <QTextEdit>
#include "data.h"

namespace ptzs {

class AnnouncementEditor : public QWidget
{
    Q_OBJECT
public:
    explicit AnnouncementEditor(QWidget *parent = nullptr);

private:
    QGridLayout *layout;
    QTextEdit *te;

signals:

public slots:
    void setAnnouncement();
};

} // namespace ptzs

#endif // ANNOUNSEMENTEDITOR_H
