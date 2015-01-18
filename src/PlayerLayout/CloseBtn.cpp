/**
    Provide by Walon Li, YJ Fang

    File PictureComponent.cpp
**/

#include <QDebug>
#include <QPainter>
#include <QTimerEvent>
#include "include/PlayerLayout/CloseBtn.h"


pdr::CloseBtn::CloseBtn(QWidget *parent):
    QAbstractButton(parent),
    pixmap_("image/close.png"),
    progress_(0)
    //icon_(pixmap_)
{
    // connect to play_window widget
    this->connect(this,
                  SIGNAL(clicked()),
                  parent->parentWidget()->parentWidget(),
                  SLOT(closeBtnClickSlot())) ;
    this->hide();
    this->startTimer(50) ;
}

void pdr::CloseBtn::timerEvent(QTimerEvent *e)
{
    if (!progress_) this->show();

    this->move(736, progress_*16-64);
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
