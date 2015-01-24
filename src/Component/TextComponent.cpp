/**
    Provide by Walon Li, YJ Fang

    File PictureComponent.cpp
**/

#include "include/Component/TextComponent.h"
#include "include/Effective/LinearMoveEffect.h"
#include <QDebug>
#include <boost/thread.hpp>
#include <QThread>


pdr::TextComponent::TextComponent(pdr::TextItem *t, QPointF p, Effective *e):
    Component(NULL),
    item_(t),
    rect_(),
    pos_(p),
    effect_(e)
{
    if (pos_.isNull())
    {
        // if not to assign poistion, put it to middle-down.

        qreal x = item_->getItemRectF().width();
        qreal y = item_->getItemRectF().height();

        rect_ = QRectF(0,0,x,y) ;
        pos_ = QPointF((800-x)/2, 600-y-30) ;
    }

    if (effect_)
    {
        effect_->prepare(this);
    }
}

pdr::TextComponent::~TextComponent()
{
    delete item_ ;
    delete effect_ ;
}

void pdr::TextComponent::timerEvent(QTimerEvent* e)
{

    if (pause_flag_)
    {
        this->killTimer(e->timerId());
    }
    else
    {
        if (effect_)
            effect_->play(this);
    }

}

void pdr::TextComponent::paint(QPainter *painter,
                               const QStyleOptionGraphicsItem *,
                               QWidget *)
{
    QPen pen ;
    pen.setColor(item_->getColor());
    painter->setPen(pen);
    painter->setFont(item_->getFont());

    if (effect_)
        effect_->draw(this, painter, item_->getString().c_str());
    else
        painter->drawText(pos_, item_->getString().c_str());
    //painter->drawText(0,0, item_->getString().c_str());
    //if (effect_)
    //
}

QRectF pdr::TextComponent::boundingRect() const
{
    //return rect_ ;
    return QRectF(0,0,800,600) ;
}

void pdr::TextComponent::play()
{
    this->startTimer(50) ;
}

void pdr::TextComponent::pause()
{
    pause_flag_ = true ;
}

void pdr::TextComponent::resume()
{
    pause_flag_ = false ;
    this->startTimer(50) ;
}

void pdr::TextComponent::stop()
{
}



