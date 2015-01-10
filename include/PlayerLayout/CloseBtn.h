/**
    Provide by Walon Li, YJ Fang

    File PictureComponent.h
**/

#ifndef CLOSE_BTN_H
#define CLOSE_BTN_H

#include <QImage>
#include <QPainter>
#include <QGraphicsItem>
#include <QRectF>
#include <QPushButton>
#include <QBitmap>
#include <QIcon>

namespace pdr
{
class CloseBtn : public QAbstractButton
{

public :
    explicit CloseBtn(QWidget *parent=0);
    virtual ~CloseBtn(){}

    void paintEvent(QPaintEvent*) ;
    QSize sizeHint() const ;
protected:
    // Override paint event.
    // void paintEvent(QPaintEvent *event) ;

private :
    QPixmap pixmap_ ;
    QIcon icon_ ;
} ;
}
#endif
