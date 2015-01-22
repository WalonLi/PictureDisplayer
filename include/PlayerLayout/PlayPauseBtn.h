/**
    Provide by Walon Li, YJ Fang

    File PictureComponent.h
**/

#ifndef PLAY_PAUSE_BTN_H
#define PLAY_PAUSE_BTN_H

#include "AbstractPlayerButton.h"

namespace pdr
{
class PlayPauseBtn : public AbstractPlayerButton
{
    //Q_OBJECT

public :
    explicit PlayPauseBtn(QWidget *parent=0);
    virtual ~PlayPauseBtn(){};

    void paintEvent(QPaintEvent*) ;
    QSize sizeHint() const ;

    void setBtnPixmap(bool flag) ;

    void timerEvent(QTimerEvent *e) ;
    void play() ;
private :
    QPixmap pixmap_ ;
    QPixmap play_pixmap_ ;
    QPixmap pause_pixmap_ ;
} ;
}
#endif
