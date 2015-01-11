/**
    Provide by Walon Li, YJ Fang

    File PictureComponent.cpp
**/

#include <QDebug>
#include <QPainter>
#include "include/PlayerLayout/CloseBtn.h"


pdr::CloseBtn::CloseBtn(QWidget *parent):
    QAbstractButton(parent),
    pixmap_("image/close.png")
    //icon_(pixmap_)
{
    //icon_.addPixmap(pixmap_);
    //this->setIcon(icon_);
    //this->setIconSize(QSize(64,64));
    this->setGeometry(736,0,800,64) ;
    //this->setMask(pixmap_.mask()) ;

    // connect to play_window widget
    this->connect(this,
                  SIGNAL(clicked()),
                  parent->parentWidget()->parentWidget(),
                  SLOT(closeBtnClickSlot())) ;
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
