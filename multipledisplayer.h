#ifndef MULTIPLEDISPLAYER_H
#define MULTIPLEDISPLAYER_H

#include <QWidget>

namespace ptzs {

class MultipleDisplayer : public QWidget
{
    Q_OBJECT
public:
    explicit MultipleDisplayer(QWidget *parent = nullptr);

signals:

public slots:
};

} // namespace ptzs

#endif // MULTIPLEDISPLAYER_H