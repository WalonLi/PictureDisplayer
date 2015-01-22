/**
    Provide by Walon Li, YJ Fang

    File CycleBtn.h
**/

#ifndef CYCLE_BTN_H
#define CYCLE_BTN_H

#include "AbstractPlayerButton.h"

namespace pdr
{
class CycleBtn : public AbstractPlayerButton
{

public :
    explicit CycleBtn(QWidget *parent=0);
    virtual ~CycleBtn(){}

    void paintEvent(QPaintEvent*) ;
    QSize sizeHint() const ;

    void timerEvent(QTimerEvent *e) ;
    void play() ;
private :
    QPixmap pixmap_ ;
} ;
}
#endif
