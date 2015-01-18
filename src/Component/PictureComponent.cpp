/**
    Provide by Walon Li, YJ Fang

    File PictureComponent.cpp
**/

#include "include/Component/PictureComponent.h"
#include "include/Effective/LinearMoveEffect.h"
#include <QDebug>
#include <QStyleOptionGraphicsItem>
#include <boost/thread.hpp>
#include <QThread>


pdr::PictureComponent::PictureComponent(QImage *i, Scale s, QPointF p, Effective *e):
    Component(NULL),
    image_(i),
    scale_(s),
    pos_(p),
    effect_(e)
{
    switch (scale_)
    {
        // scale image
        case Scale::IgnoreAspecRatio:
        {
            QImage *temp = image_ ;
            image_ = new QImage(image_->scaled(800, 600, Qt::IgnoreAspectRatio));
            delete temp ;
            break ;
        }
        default:
            break ;
    }

    if (pos_.isNull())
    {
        // put it to center
        qreal width = (image_->width() > 800) ? 800 : image_->width() ;
        qreal height = (image_->height() > 600) ? 600 : image_->height() ;
        pos_ = QPointF((800-width)/2, (600-height)/2) ;
    }

    if (effect_)
    {
        // set effect
        if (LinearMoveEffect* ptr = dynamic_cast<LinearMoveEffect*>(effect_))
            this->moveBy(ptr->getStartPos().x(), ptr->getStartPos().y());
    }
}

pdr::PictureComponent::~PictureComponent()
{
    delete image_ ;
    delete effect_ ;

}

void pdr::PictureComponent::timerEvent(QTimerEvent* e)
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

void pdr::PictureComponent::paint(QPainter *painter,
                                  const QStyleOptionGraphicsItem *,
                                  QWidget *)
{
    painter->drawImage(pos_, *image_);
}

QRectF pdr::PictureComponent::boundingRect() const
{
    return QRectF(0,0,800,600) ;
}

void pdr::PictureComponent::play()
{
    this->startTimer(50) ;
}

void pdr::PictureComponent::pause()
{
    pause_flag_ = true ;
}

void pdr::PictureComponent::resume()
{
    pause_flag_ = false ;
    this->startTimer(50) ;
}

void pdr::PictureComponent::stop()
{
}



