/**
    Provide by Walon Li, YJ Fang

    File PictureComponent.cpp
**/

#include <QDebug>
#include <QPainter>
#include <QTimerEvent>
#include "include/PlayerLayout/PlayPauseBtn.h"


pdr::PlayPauseBtn::PlayPauseBtn(QWidget *parent):
    AbstractPlayerButton(parent),
    pixmap_("image/pause.png"),
    play_pixmap_("image/play.png"),
    pause_pixmap_("image/pause.png")
{
    this->connect(this,
                  SIGNAL(clicked()),
                  parent->parentWidget()->parentWidget(),
                  SLOT(ppBtnClickSlot())) ;
    this->hide();
}

void pdr::PlayPauseBtn::timerEvent(QTimerEvent *e)
{
    if (!progress_) this->show();

    this->move(896-(progress_*16), 530);
    progress_++ ;

    if (progress_ >= 11)
        this->killTimer(e->timerId());
}

void pdr::PlayPauseBtn::setBtnPixmap(bool flag)
{
    pixmap_ = flag ? play_pixmap_ : pause_pixmap_ ;
    this->update() ;
}

void pdr::PlayPauseBtn::paintEvent(QPaintEvent *)
{
    QPainter p(this) ;
    p.drawPixmap(0,0, pixmap_);
}

QSize pdr::PlayPauseBtn::sizeHint() const
{
    return pixmap_.size() ;
}

void pdr::PlayPauseBtn::play()
{
    progress_ = 0 ;
    this->startTimer(50) ;
}
