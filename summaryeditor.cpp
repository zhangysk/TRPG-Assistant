#include "summaryeditor.h"

namespace ptzs {

SummaryEditor::SummaryEditor(QWidget *parent) : QWidget(parent)
{
    layout=new QGridLayout(this);
    layout->setMargin(0);
    te=new QTextEdit(this);
    int i=QFontDatabase::addApplicationFont(":/font/HYZhuZiHeiMoFaW.ttf");
    QString n = QFontDatabase::applicationFontFamilies(i).at(0);
    QFont font(n);
    font.setPixelSize(20);
    te->setFont(font);
    te->setStyleSheet("background-color:transparent;");
    layout->addWidget(te,0,0);
}

} // namespace ptzs
