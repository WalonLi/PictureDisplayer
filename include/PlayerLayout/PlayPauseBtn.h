/**
    Provide by Walon Li, YJ Fang

    File PictureComponent.h
**/

#ifndef PLAY_PAUSE_BTN_H
#define PLAY_PAUSE_BTN_H

#include <QImage>
#include <QPainter>
#include <QRectF>
#include <QBitmap>
#include <QIcon>
#include <QAbstractButton>

namespace pdr
{
class PlayPauseBtn : public QAbstractButton
{
    //Q_OBJECT

public :
    explicit PlayPauseBtn(QWidget *parent=0);
    virtual ~PlayPauseBtn(){};

    void paintEvent(QPaintEvent*) ;
    QSize sizeHint() const ;

    void setBtnPixmap(bool flag) ;

    void timerEvent(QTimerEvent *e) ;

private :
    QPixmap pixmap_ ;
    QPixmap play_pixmap_ ;
    QPixmap pause_pixmap_ ;
    qreal progress_ ;
    // QIcon icon_ ;
} ;
}
#endif
