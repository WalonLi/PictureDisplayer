/**
    Provide by Walon Li, YJ Fang

    File PictureComponent.cpp
**/

#include <QDebug>
#include <QPainter>
#include "../include/Button/PlayPauseBtn.h"


pdr::PlayPauseBtn::PlayPauseBtn(QWidget *parent):
    QAbstractButton(parent),
    pixmap_("../image/play.png"),
    icon_(pixmap_)
{
    //icon_.addPixmap(pixmap_);
    this->setIcon(icon_);
    this->setIconSize(QSize(64,64));
    this->setGeometry(0,0,64,64) ;
    //this->setMask(pixmap_.mask()) ;
}

void pdr::PlayPauseBtn::paintEvent(QPaintEvent *e)
{
    QPainter p(this) ;
    p.drawPixmap(0,0, pixmap_);
}

QSize pdr::PlayPauseBtn::sizeHint() const
{
    return pixmap_.size() ;
}
