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
    pos_(p),
    effect_(e)
{
    if (pos_.isNull())
    {
        // if not to assign poistion, put it to middle-down.
        QFontMetrics metric(item_->getFont()) ;

        qreal x = 0;
        qreal y = item_->getFont().pixelSize() ;
        std::string str = item_->getString() ;
        for (auto it = str.begin() ; it != str.end() ; ++it)
            x += metric.width(*it) ;

        pos_ = QPointF((800-x)/2, 600-y-30) ;
    }

    if (effect_)
    {
        effect_->prepare(this);
        //if (LinearMoveEffect* ptr = dynamic_cast<LinearMoveEffect*>(effect_))
        //    this->moveBy(ptr->getStartPos().x(), ptr->getStartPos().y());
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
    painter->drawText(pos_, item_->getString().c_str());
}

QRectF pdr::TextComponent::boundingRect() const
{
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



