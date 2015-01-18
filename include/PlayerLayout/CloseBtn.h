/**
    Provide by Walon Li, YJ Fang

    File PictureComponent.h
**/

#ifndef CLOSE_BTN_H
#define CLOSE_BTN_H

#include <QImage>
#include <QPainter>
#include <QRectF>
#include <QBitmap>
#include <QIcon>
#include <QAbstractButton>

namespace pdr
{
class CloseBtn : public QAbstractButton
{

public :
    explicit CloseBtn(QWidget *parent=0);
    virtual ~CloseBtn(){}

    void paintEvent(QPaintEvent*) ;
    QSize sizeHint() const ;

    void timerEvent(QTimerEvent *e) ;
private :
    QPixmap pixmap_ ;
    qreal progress_ ;
    // QIcon icon_ ;
} ;
}
#endif
