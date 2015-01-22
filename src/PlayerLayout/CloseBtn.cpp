/**
    Provide by Walon Li, YJ Fang

    File PictureComponent.cpp
**/

#include <QDebug>
#include <QPainter>
#include <QTimerEvent>
#include "include/PlayerLayout/CloseBtn.h"


pdr::CloseBtn::CloseBtn(QWidget *parent):
    AbstractPlayerButton(parent),
    pixmap_("image/close.png")
{
    // connect to play_window widget
    this->connect(this,
                  SIGNAL(clicked()),
                  parent->parentWidget()->parentWidget(),
                  SLOT(closeBtnClickSlot())) ;
    this->hide();
}

void pdr::CloseBtn::timerEvent(QTimerEvent *e)
{
    if (!progress_) this->show();

    this->move(800-(progress_*16), 0);
    progress_++ ;

    if (progress_ >= 5)
        this->killTimer(e->timerId());
}

void pdr::CloseBtn::paintEvent(QPaintEvent *)
{
    QPainter p(this) ;
    p.drawPixmap(0,0, pixmap_);
}

QSize pdr::CloseBtn::sizeHint() const
{
    return pixmap_.size() ;
}

void pdr::CloseBtn::play()
{
    progress_ = 0 ;
    this->startTimer(50) ;
}
