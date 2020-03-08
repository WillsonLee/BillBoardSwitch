#include "piclabel.h"


PicLabel::PicLabel(QWidget *parent, Qt::WindowFlags f):QLabel(parent,f)
{
    imageLoaded=false;
    this->setMouseTracking(true);
}

void PicLabel::setImage(const QImage &img)
{
    QPixmap pix=QPixmap::fromImage(img);
    this->setPixmap(pix);
    this->setText("");
    imageLoaded=true;
}

void PicLabel::mouseMoveEvent(QMouseEvent *event)
{
    if(imageLoaded){
        emit coordXChanged(event->pos().x());
        emit coordYChanged(event->pos().y());
    }
}

void PicLabel::enterEvent(QEvent *event)
{
    if(imageLoaded){
        this->setCursor(Qt::CrossCursor);
    }
}

void PicLabel::leaveEvent(QEvent *event)
{
    if(imageLoaded){
        this->setCursor(Qt::ArrowCursor);
    }
}

void PicLabel::mouseReleaseEvent(QMouseEvent *event)
{
    emit clicked(imageLoaded);
}
