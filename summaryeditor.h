#ifndef SUMMARYEDITOR_H
#define SUMMARYEDITOR_H

#include <QWidget>
#include <QGridLayout>
#include <QTextEdit>
#include <QPushButton>

namespace ptzs {

class SummaryEditor : public QWidget
{
    Q_OBJECT
public:
    explicit SummaryEditor(QWidget *parent = nullptr);

private:
    QGridLayout* layout;
    QTextEdit *te;
    QPushButton *button;

signals:

public slots:
};

} // namespace ptzs

#endif // SUMMARYEDITOR_H
