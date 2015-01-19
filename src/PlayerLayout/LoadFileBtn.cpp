/**
    Provide by Walon Li, YJ Fang

    File LoadFileBtn.cpp
**/

#include <QDebug>
#include <QPainter>
#include <QTimerEvent>
#include "include/PlayerLayout/LoadFileBtn.h"


pdr::LoadFileBtn::LoadFileBtn(QWidget *parent):
    QAbstractButton(parent),
    pixmap_("image/load.png"),
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
