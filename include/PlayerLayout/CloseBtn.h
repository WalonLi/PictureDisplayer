/**
    Provide by Walon Li, YJ Fang

    File PictureComponent.h
**/

#ifndef CLOSE_BTN_H
#define CLOSE_BTN_H

#include "AbstractPlayerButton.h"

namespace pdr
{
class CloseBtn : public AbstractPlayerButton
{

public :
    explicit CloseBtn(QWidget *parent=0);
    virtual ~CloseBtn(){}

    void paintEvent(QPaintEvent*) ;
    QSize sizeHint() const ;

    void timerEvent(QTimerEvent *e) ;

    void play() ;
private :
    QPixmap pixmap_ ;
    // QIcon icon_ ;
} ;
}
#endif
