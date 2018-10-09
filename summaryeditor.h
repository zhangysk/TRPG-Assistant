#ifndef SUMMARYEDITOR_H
#define SUMMARYEDITOR_H

#include <QWidget>
#include <QGridLayout>
#include <QTextEdit>
#include "data.h"

namespace ptzs {

class SummaryEditor : public QWidget
{
    Q_OBJECT
public:
    explicit SummaryEditor(QWidget *parent = nullptr);

private:
    QGridLayout* layout;
    QTextEdit *te;

signals:

public slots:
    void setSummary();
};

} // namespace ptzs

#endif // SUMMARYEDITOR_H
