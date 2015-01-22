/**
    Provide by Walon Li, YJ Fang

    File LoadFileBtn.cpp
**/

#include <QDebug>
#include <QPainter>
#include <QTimerEvent>
#include "include/PlayerLayout/LoadFileBtn.h"


pdr::LoadFileBtn::LoadFileBtn(QWidget *parent):
    AbstractPlayerButton(parent),
    pixmap_("image/load.png")
{
    // connect to play_window widget
    /*
    this->connect(this,
                  SIGNAL(clicked()),
                  parent->parentWidget()->parentWidget(),
                  SLOT(closeBtnClickSlot())) ;
                  */
    this->hide();
}

void pdr::LoadFileBtn::timerEvent(QTimerEvent *e)
{
    if (!progress_) this->show();

    this->move(832-(progress_*16), 370);
    progress_++ ;

    if (progress_ >= 7)
        this->killTimer(e->timerId());
}

void pdr::LoadFileBtn::paintEvent(QPaintEvent *)
{
    QPainter p(this) ;
    p.drawPixmap(0,0, pixmap_);
}

QSize pdr::LoadFileBtn::sizeHint() const
{
    return pixmap_.size() ;
}

void pdr::LoadFileBtn::play()
{
    progress_ = 0 ;
    this->startTimer(50) ;
}
