/**
    Provide by Walon Li, YJ Fang

    File PictureComponent.cpp
**/

#include <QDebug>
#include <QPainter>
#include <QTimerEvent>
#include <QPaintEvent>
#include "include/PlayerLayout/CloseBtn.h"
#include "include/PlayerLayout/ButtonEventFiler.h"

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
    //this->setMouseTracking(true);
    //this->setFocusPolicy(Qt::NoFocus);
    //this->installEventFilter(new ButtonEventFiler());
    //this->setAttribute(Qt::WA_TranslucentBackground);
}

void pdr::CloseBtn::timerEvent(QTimerEvent *e)
{
    if (!progress_) this->show();

    this->move(800-(progress_*16), 0);

    if (this->pos().x() <= 736)
    {
        this->killTimer(e->timerId());
        return ;
    }
    progress_++ ;
}

void pdr::CloseBtn::paintEvent(QPaintEvent *e)
{
    //this->setWindowOpacity(1);
    //bitBlt(this, 0, 0, &pm);
    //qDebug() << "paint" ;

    QPainter p(this) ;

    //p.begin(this) ;
    p.drawPixmap(0,0, pixmap_);

    //p.end();
    //qDebug() << "123" ;
}

QSize pdr::CloseBtn::sizeHint() const
{
    return pixmap_.size() ;
}

void pdr::CloseBtn::play()
{
    progress_ = 0 ;
    this->startTimer(50, Qt::PreciseTimer) ;
}
