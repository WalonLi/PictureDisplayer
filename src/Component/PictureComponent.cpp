/**
    Provide by Walon Li, YJ Fang

    File PictureComponent.cpp
**/

#include "include/Component/PictureComponent.h"
#include <QDebug>
#include <QStyleOptionGraphicsItem>
#include <boost/thread.hpp>
#include <QThread>


pdr::PictureComponent::PictureComponent(QImage *i, Scale s, Effective *e):
    Component(NULL),
    image_(i),
    scale_(s),
    effect_(e)
{
    switch (scale_)
    {
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
}

pdr::PictureComponent::~PictureComponent()
{
    delete image_ ;
    delete effect_ ;

}

void pdr::PictureComponent::timerEvent(QTimerEvent* e)
{
    // qDebug() << "timerEvent" ;
    // static int count = 0 ;
    if (pause_flag_)
    {
        this->killTimer(e->timerId());
    }
    else
    {
        /*
        // draw animation
        count++ ;
        if (count == 1)
            this->moveBy(10,10);
        else if (count == 2)
            this->moveBy(10,10);
        else if (count == 3)
            this->moveBy(-10,-10);
        else if (count == 4)
            this->moveBy(-10,-10);
        */
    }
}

// void pdr::PictureComponent::paintEvent(QPaintEvent *event)
void pdr::PictureComponent::paint(QPainter *painter,
                                  const QStyleOptionGraphicsItem *,
                                  QWidget *)
{
    qreal width = (image_->width() > 800) ? 800 : image_->width() ;
    qreal height = (image_->height() > 600) ? 600 : image_->height() ;
    painter->drawImage((800-width)/2, (600-height)/2, *image_);
}

QRectF pdr::PictureComponent::boundingRect() const
{
    return QRectF(0,0,800,600) ;
}

void pdr::PictureComponent::play()
{
    this->startTimer(100) ;
}

void pdr::PictureComponent::pause()
{
    // qDebug() << "Picture pasue" ;
    pause_flag_ = true ;
}

void pdr::PictureComponent::resume()
{
    // qDebug() << "Picture resume" ;
    pause_flag_ = false ;
    this->startTimer(100) ;
}

void pdr::PictureComponent::stop()
{
    // this->thread()->exit();
}



