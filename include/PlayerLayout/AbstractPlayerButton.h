/**
    Provide by Walon Li, YJ Fang

    File PlaywrWindow.h
**/

#ifndef ABSTRACT_PLAYER_BUTTON_H
#define ABSTRACT_PLAYER_BUTTON_H

#include <QImage>
#include <QPainter>
#include <QRectF>
#include <QBitmap>
#include <QAbstractButton>

namespace pdr
{
class AbstractPlayerButton : public QAbstractButton
{

public :
    explicit AbstractPlayerButton(QWidget *parent=0):
        QAbstractButton(parent),
        progress_(0){}

    virtual ~AbstractPlayerButton(){}

    virtual void paintEvent(QPaintEvent*) = 0;
    virtual QSize sizeHint() const = 0;

    virtual void timerEvent(QTimerEvent *e) = 0;

    virtual void play() = 0;
protected :
    qreal progress_ ;
} ;
}
#endif
