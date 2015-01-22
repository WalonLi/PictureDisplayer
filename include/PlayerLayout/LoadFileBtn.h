/**
    Provide by Walon Li, YJ Fang

    File LoadFileBtn.h
**/

#ifndef LOAD_FILE_BTN_H
#define LOAD_FILE_BTN_H

#include "AbstractPlayerButton.h"

namespace pdr
{
class LoadFileBtn : public AbstractPlayerButton
{

public :
    explicit LoadFileBtn(QWidget *parent=0);
    virtual ~LoadFileBtn(){}

    void paintEvent(QPaintEvent*) ;
    QSize sizeHint() const ;

    void timerEvent(QTimerEvent *e) ;
    void play() ;
private :
    QPixmap pixmap_ ;
} ;
}
#endif
