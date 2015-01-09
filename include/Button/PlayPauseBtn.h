/**
    Provide by Walon Li, YJ Fang

    File PictureComponent.h
**/

#ifndef PLAY_PAUSE_BTN_H
#define PLAY_PAUSE_BTN_H

#include <QImage>
#include <QPainter>
#include <QGraphicsItem>
#include <QRectF>
#include <QPushButton>
#include <QBitmap>
#include <QIcon>

namespace pdr
{
class PlayPauseBtn : public QAbstractButton
{
    //Q_OBJECT

public :
    explicit PlayPauseBtn(QWidget *parent=0);
    virtual ~PlayPauseBtn(){}

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
