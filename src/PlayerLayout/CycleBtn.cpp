/**
    Provide by Walon Li, YJ Fang

    File CycleBtn.cpp
**/

#include <QDebug>
#include <QPainter>
#include <QTimerEvent>
#include "include/PlayerLayout/CycleBtn.h"


pdr::CycleBtn::CycleBtn(QWidget *parent):
    QAbstractButton(parent),
    pixmap_("image/cycle.png"),
    progress_(0)
    //icon_(pixmap_)
{
    //icon_.addPixmap(pixmap_);
    //this->setIcon(icon_);
    // this->setIconSize(QSize(64,64));
    // this->setGeometry(736,0,800,64) ;

    //this->setMask(pixmap_.mask()) ;

    // connect to play_window widget
    /*
    this->connect(this,
                  SIGNAL(clicked()),
                  parent->parentWidget()->parentWidget(),
                  SLOT(closeBtnClickSlot())) ;
                  */
    this->hide();
    this->startTimer(50) ;
}

void pdr::CycleBtn::timerEvent(QTimerEvent *e)
{
    if (!progress_) this->show();

    this->move(864-(progress_*16), 450);
    progress_++ ;

    if (progress_ >= 9)
        this->killTimer(e->timerId());
}

void pdr::CycleBtn::paintEvent(QPaintEvent *)
{
    QPainter p(this) ;
    p.drawPixmap(0,0, pixmap_);
}

QSize pdr::CycleBtn::sizeHint() const
{
    return pixmap_.size() ;
}
