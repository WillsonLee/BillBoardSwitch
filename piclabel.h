#ifndef PICLABEL_H
#define PICLABEL_H

#include <QObject>
#include <QWidget>
#include <QLabel>
#include "stable.h"

class PicLabel : public QLabel
{
    Q_OBJECT
public:
    PicLabel(QWidget *parent=Q_NULLPTR, Qt::WindowFlags f=Qt::WindowFlags());
    void setImage(const QImage &img);

    // QWidget interface
protected:
    void mouseMoveEvent(QMouseEvent *event);
    void enterEvent(QEvent *event);
    void leaveEvent(QEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
private:
    bool imageLoaded;
signals:
    void coordXChanged(int x);
    void coordYChanged(int y);
    void clicked(bool loaded);
};

#endif // PICLABEL_H
